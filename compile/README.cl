/***********************************************************************/
/**   compile CLAIRE                                    Yves Caseau    */
/**   readme.cl                                                        */
/**   Copyright (C) 1998-2013 Yves Caseau. All Rights Reserved.        */
/***********************************************************************/


This directory contains the files for two compiler modules: Optimize & Generate.
Optimize is the "target-code-independant" part of the compiler : from CLAIRE instruction
to optimized-claire-instruction.
Generate is the target code compiler, geared towards C++.
However, it has made generic so that other target languages may be plugged (see the JLight compiler
module as a Java example)


/****************/
/**  Optimize  **/
/****************/

CLAIRE instruction-to-instruction optimization is defined by a handful of methods:

  c_type(x)  is the CLAIRE type of x
  c_code(x)  is an optimized instruction
  & c_code(x,s) is an optimized expression of sort s
  c_gc?(x)   [boolean] true if x must be protected from garbage collection
  c_sort(x)  the sort of the expression x (precise sort)
  c_status(x,l) [bitvector] abstract interpretation of x according to a set
             of criterions (allocation, update, etc...)

The sort is a class sub-hierarchy which has an homogeneous way to be translated into the
target language. Here th sorts are integer, char, x <= imported, object, entity

osystem.cl      This file contains the gloabal parameter objects and the key methods: c_type, c_code, c_gc?, c_sort, c_status
otool.cl        This file contains the auxiliairy methods for the source optimizer
ocall.cl        this is the heart of the CLAIRE optimizer : message to function calls
ocontrol.cl     contains the optimizer for the control structures - most of them are replaced with simpler structures
                that may be translated directly into the target language
odefine.cl      optimization of the definition instruction -> sort-of macroexpansion

// ******************************************************************
// *   contents of osystem.cl                                       *
// *    Part 1: General Global Variables and Properties             *
// *    Part 2: The defaults for c_type, c_code, c_gc and c_sort    *
// *    Part 3: c_new, c_sort, c_fonc                               *
// *    Part 4: Names & identifiers management                      *
// *    Part 5: On-line optimization                                *
// ******************************************************************
// ******************************************************************
// *  contents of otool.cl                                          *
// *    Part 1: New Instructions & associated stuff                 *
// *    Part 2: Optimizer Warnings                                  *
// *    Part 3: Type Handling                                       *
// *    Part 4: Garbage Collection functions                        *
// *    Part 5: Miscellaneous                                       *
// ******************************************************************
// ******************************************************************
// *  Contents of ocall.cl                                          *
// *    Part 1: Restruction Binding                                 *
// *    Part 2: Generic c_type & c_code                             *
// *    Part 3: specialized c_code                                  *
// *    Part 4: Method optimizing                                   *
// *    Part 5: inline methods                                      *
// ******************************************************************
// ******************************************************************
// * Contents of ocontrol.cl                                        *
// *     Part 1: Basic Instructions                                 *
// *     Part 2: other control structures                           *
// *     Part 3: If, Case, Do, Let                                  *
// *     Part 4: Loops                                              *
// *     Part 5: Iterate                                            *
// ******************************************************************
// ******************************************************************
// *  Contents of define.cl                                         *
// *     Part 1: Set, List and Tuple creation                       *
// *     Part 2: Object definition                                  *
// *     Part 3: Method instantiation                               *
// *     Part 4: Inverse Management                                 *
// ******************************************************************

/****************/
/**  Generate  **/
/****************/


gsystem.cl contains the toplevel methods that tell how to compile a file or a module.

gexp.cl contains the definition of the "expression" method, which produces an expression
of the target language from a CLAIRE optimized expression x that must satisfy 
c_func(x) = true

gstat.cl contains the definition of the "statement" method which produces a statement
         from the external target language from a CLAIRE optimized instruction.

cgen.cl contains the definition of the C++ code producer, which encapsulate all that is
        truly specific to C++. This separation allows for the definition of alternate
        producers, such as Java.

copt.cl contains even more specific inline optimization (fragments of C++ code that
        speed up key methods & control structures)

jgen.cl contains the java code generation file (Bouygues e-Lab)

// *********************************************************************
// * Contents of gsystem.cl                                            *
// *          Part 1: Global_variables & producer interface            *
// *          Part 2: Module Compiler Interface                        *
// *          Part 3: File Compiler                                    *
// *          Part 4: Function Compiler                                *
// *********************************************************************
// *********************************************************************
// *  contents of gexp.cl                                              *
// *  Part 1: c_func & expression for objects                          *
// *  Part 2: expression for messages                                  *
// *  Part 3: expression for structures                                *
// *  Part 4: boolean optimization                                     *
// *********************************************************************
// *********************************************************************
// *  contents of gstat.cl:                                            *
// *          Part 1: Unfolding of complex expressions                 *
// *          Part 2: Basic control structures                         *
// *          Part 3: iteration                                        *
// *          Part 4: CLAIRE-specific structures                       *
// *********************************************************************
// *********************************************************************
// * Contents of cgen.cl                                               *
// *     Part 1: definition of the C++ code producer                   *
// *     Part 2: utilities for file generation                         *
// *     Part 3: interface declarations                                *
// *     Part 4: use of language dependent patterns (macros)           *
// *     Part 5: System compiling methods                              *
// *********************************************************************
// *********************************************************************
// * Contents of copt.cl                                               *
// *     Part 1: the inline coding of function calls                   *
// *     Part 2: Fast dispatch (inlining method selection)             *
// *     Part 3: Specific code for expressions                         *
// *     Part 4: Specific code for control structures                  *
// *********************************************************************
