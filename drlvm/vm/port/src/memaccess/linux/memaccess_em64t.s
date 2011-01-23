//
//  Licensed to the Apache Software Foundation (ASF) under one or more
//  contributor license agreements.  See the NOTICE file distributed with
//  this work for additional information regarding copyright ownership.
//  The ASF licenses this file to You under the Apache License, Version 2.0
//  (the "License"); you may not use this file except in compliance with
//  the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
    .text

// port_memcpy_asm(void* dst, const void* src, size_t size,
//                 void** prestart_addr, void* memcpyaddr);
// 1st arg (RDI) - dest
// 2nd arg (RSI) - src
// 3rd arg (RDX) - len
// 4th arg (RCX) - address of restart_address storage
// 5th arg (R8)  - address of memcpy - to avoid PIC problems in GNU asm

.globl _port_memcpy_asm
_port_memcpy_asm:
    pushq   %rbx
    callq   _precall
_precall:
    popq    %rax
    addq    _preret(%rip), %rax
    subq    _precall(%rip), %rax
    movq    %rax, (%rcx)

    callq   *%r8

_preret:
    popq    %rbx
    ret
