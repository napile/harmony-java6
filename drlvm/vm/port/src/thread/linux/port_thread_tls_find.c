/*
 *  Licensed to the Apache Software Foundation (ASF) under one or more
 *  contributor license agreements.  See the NOTICE file distributed with
 *  this work for additional information regarding copyright ownership.
 *  The ASF licenses this file to You under the Apache License, Version 2.0
 *  (the "License"); you may not use this file except in compliance with
 *  the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <dlfcn.h>
#include "port_thread_internal.h"


#if defined(MACOSX)
#define SHPORT_SH_NAME ("lib" CH_SHLIB_NAME ".dylib")
#else
#define SHPORT_SH_NAME ("lib" CH_SHLIB_NAME ".so")
#endif

volatile port_shared_data_t* port_shared_data = NULL;

typedef int (*fn_port_init_shared_data_t)(volatile port_shared_data_t** pdata);


int init_port_shared_data()
{
    void* native_handle;
    fn_port_init_shared_data_t fn_ptr;

    if (port_shared_data)
        return 0;

    native_handle = dlopen(SHPORT_SH_NAME, RTLD_NOW | RTLD_GLOBAL);

    if (native_handle == NULL)
        return -1;

    fn_ptr =
        (fn_port_init_shared_data_t)dlsym(native_handle, "port_init_shared_data");

    if (!fn_ptr)
        return -1;

    return fn_ptr(&port_shared_data);
}
