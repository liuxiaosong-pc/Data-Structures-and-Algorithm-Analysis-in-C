/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：FatalError.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-25
Function List ：
Description   ：Fatal Error
******************************************************/

#ifndef FATALERROR_H
#define FATALERROR_H

#include <stdio.h>   // for fprintf
#include <stdlib.h>  // for exit

#define Error(Str)        FatalError(Str)
#define FatalError(Str)   fprintf(stderr, "%s\n", Str), exit(1)

#endif  /* FATALERROR_H */

// EOF

