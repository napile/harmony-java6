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

/**
 * @author Serguei S.Zapreyev
 */

/*
 * THE FILE HAS BEEN AUTOGENERATED BY INTEL IJH TOOL.
 * Please be aware that all changes made to this file manually
 * will be overwritten by the tool if it runs again.
 */

#include <jni.h>


/* Header for class java.lang.System */

#ifndef _JAVA_LANG_SYSTEM_H
#define _JAVA_LANG_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif


/* Native methods */

/*
 * Method: java.lang.System.setErrUnsecure(Ljava/io/PrintStream;)V
 */
JNIEXPORT void JNICALL
Java_java_lang_System_setErrUnsecure(JNIEnv *, jclass, 
    jobject);

/*
 * Method: java.lang.System.setInUnsecure(Ljava/io/InputStream;)V
 */
JNIEXPORT void JNICALL
Java_java_lang_System_setInUnsecure(JNIEnv *, jclass, 
    jobject);

/*
 * Method: java.lang.System.setOutUnsecure(Ljava/io/PrintStream;)V
 */
JNIEXPORT void JNICALL
Java_java_lang_System_setOutUnsecure(JNIEnv *, jclass, 
    jobject);

/*
 * Method: java.lang.System.rethrow(Ljava/lang/Throwable;)V
 */
JNIEXPORT void JNICALL
Java_java_lang_System_rethrow(JNIEnv *, jclass, 
    jthrowable);


#ifdef __cplusplus
}
#endif

#endif /* _JAVA_LANG_SYSTEM_H */

