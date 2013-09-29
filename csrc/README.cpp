/***********************************************************************/
/**   microCLAIRE                                       Yves Caseau    */
/**   readme.cpp for Kernel                                            */
/**  Copyright (C) 1998-2013 Yves Caseau. All Rights Reserved.         */
/***********************************************************************/

The microCLAIRE library is made of two modules. The Kernel module is written in C++
and the Core module is written in CLAIRE and compiled into C++.

this directory contains the C++ code for the Kernel module of microCLAIRE v3.0.

last modified: 4/10/00


clAlloc.cpp   contains the ClaireAlloc class that encapsulates all alloc/gc services
              We use do not use C++ new and delete, so that we can allocate everything
              with a same reference address (&Cmemory[0]) which is necessary for OIDs.
             

clBag.cpp     contains the bag class and its 3 subclasses: array, list and set
              

clEnv.cpp     contains the environment classes:
                 ClaireRes manages worlds and symbols (+ ClaireSymbol)
                 ClaireEnv class that manages the eval and exception stacks
              

clString.cpp  contains the imported objects (Strings, Floats, int, char,...)
              

clPort.cpp    contains the ClairePort class and its subclasses
              

clReflect.cpp contains the reflective class for classes (ClaireClass) and properties
              
// ********************************************************************/
// * Contents of ClAlloc.cpp                                          */
// *    1. Interface methods                                          */
// *    2. Allocation methods                                         */
// *    3. De-allocation methods                                      */
// *    4. Garbage Collection                                         */
// *    5. Interface functions                                        */
// ********************************************************************/
// ********************************************************************/
// * Contents of ClBag.cpp                                            */
// *  1. Bags                                                         */
// *  2. Lists                                                        */
// *  3. Sets                                                         */
// *  4. Tuples                                                       */
// *  5. Arrays                                                       */
// ********************************************************************/
// ********************************************************************/
// * Contents of ClEnv.cpp                                            */
// *    1. exception handling functions                               */
// *    2. ClRes functions                                            */
// *    3. Evaluator + ClEnv functions                                */
// *    4. Function Evaluation (stack_apply)                          */
// *    5. World functions                                            */
// *    6: Encoding & Miscellaneous (will move)                       */
// ********************************************************************/
// ********************************************************************/
// * Contents of ClString.cpp                                         */
// *    1. Strings                                                    */
// *    2. Modules                                                    */
// *    3. Symbol                                                     */
// *    4. integer                                                    */
// *    5. floats                                                     */
// ********************************************************************/
// ********************************************************************/
// * Contents of ClPort.cpp                                           */
// *    1: Claire Ports                                               */
// *    3. Reader functions                                           */
// *    3. Character                                                  */
// *    4. System interface (miscellaneous)                           */
// ********************************************************************/
// ********************************************************************/
// * Contents of ClReflect.cpp                                        */
// *    1. Objects                                                    */
// *    2. Class                                                      */
// *    3. Properties                                                 */
// *    4. Tables                                                     */
// ********************************************************************/

Kernel.cpp    contains the reflective description (claireClasses) of the Kernel module
              this file is equivalent to the module description that is generated by the
              compiler

clConsole.cpp  contains the C++ code for the Console module, whicg provides a text-based interface
               for CLAIRE



In addition, this directory contains 3 test files

testKernel.cpp

testmClaire.cpp

testiClaire.cpp

and a Makefile for building the Kernel.lib library and running the different test files
