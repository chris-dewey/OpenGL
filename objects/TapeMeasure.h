#pragma once

#include <glew.h>

GLfloat tapeVerts[] = {                                                                 // Tape mesh data (hard coded vertices, indices, and texture coords)

    //*           Tape Measure
    //*
    //*        I ____________ J
    //*        /              --_  K
    //*   H  /                    | L
    //*     |G                   /
    //*    /                     | M
    //*  F|                      |
    //*   |           CP         |
    //*  E|                      |
    //*    \ D                   | N
    //*     |C                    \
        //*    /                       | O
        //*  B|   S_____________R      |
        //*   |___/              \_____|
        //*   A   T             Q       P

        // Front
        //Position				Normal Coords				Texture Coords
        -0.9f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.0f,  0.0f,    //  FA    1
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f, -0.6f,  0.3f,   0.0f, 0.0f, 1.0f,        0.0f,  0.0f,    //  FB    2
        -0.9f, -0.6f,  0.3f,   0.0f, 0.0f, 1.0f,        0.1f,  0.2f,    //  FB    2
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f, -0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.25f, 0.25f,   //  FC    3
        -0.8f, -0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.25f, 0.25f,   //  FC    3
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f, -0.4f,  0.3f,   0.0f, 0.0f, 1.0f,        0.3f,  0.3f,    //  FD    4
        -0.8f, -0.4f,  0.3f,   0.0f, 0.0f, 1.0f,        0.3f,  0.3f,    //  FD    4
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f, -0.2f,  0.3f,   0.0f, 0.0f, 1.0f,        0.05f, 0.4f,    //  FE    5
        -0.9f, -0.2f,  0.3f,   0.0f, 0.0f, 1.0f,        0.05f, 0.4f,    //  FE    5
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f,  0.2f,  0.3f,   0.0f, 0.0f, 1.0f,        0.05f, 0.6f,    //  FF    6
        -0.9f,  0.2f,  0.3f,   0.0f, 0.0f, 1.0f,        0.05f, 0.6f,    //  FF    6
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f,  0.4f,  0.3f,   0.0f, 0.0f, 1.0f,        0.1f,  0.7f,    //  FG    7
        -0.8f,  0.4f,  0.3f,   0.0f, 0.0f, 1.0f,        0.1f,  0.7f,    //  FG    7
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f,  0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.1f,  0.75f,   //  FH    8
        -0.8f,  0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.1f,  0.75f,   //  FH    8
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.3f,  0.7f,  0.3f,   0.0f, 0.0f, 1.0f,        0.35f, 0.85f,   //  FI    9
        -0.3f,  0.7f,  0.3f,   0.0f, 0.0f, 1.0f,        0.35f, 0.85f,   //  FI    9
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.4f,  0.8f,  0.3f,   0.0f, 0.0f, 1.0f,        0.7f,  0.9f,    //  FJ    10
         0.4f,  0.8f,  0.3f,   0.0f, 0.0f, 1.0f,        0.7f,  0.9f,    //  FJ    10
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f,  0.6f,  0.3f,   0.0f, 0.0f, 1.0f,        0.8f,  0.8f,    //  FK    11
         0.9f,  0.6f,  0.3f,   0.0f, 0.0f, 1.0f,        0.8f,  0.8f,    //  FK    11
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f,  0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.9f,  0.8f,    //  FL    12
         0.9f,  0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.9f,  0.8f,    //  FL    12
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.8f,  0.4f,  0.3f,   0.0f, 0.0f, 1.0f,        0.85f, 0.7f,    //  FM    13
         0.8f,  0.4f,  0.3f,   0.0f, 0.0f, 1.0f,        0.85f, 0.7f,    //  FM    13
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.8f, -0.3f,  0.3f,   0.0f, 0.0f, 1.0f,        0.85f, 0.35f,   //  FN    14
         0.8f, -0.3f,  0.3f,   0.0f, 0.0f, 1.0f,        0.85f, 0.35f,   //  FN    14
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f, -0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.95f, 0.3f,    //  FO    15
         0.9f, -0.5f,  0.3f,   0.0f, 0.0f, 1.0f,        0.95f, 0.3f,    //  FO    15
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.95f, 0.1f,    //  FP    16
         0.9f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.95f, 0.1f,    //  FP    16
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.6f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.8f,  0.1f,    //  FQ    17
         0.6f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.8f,  0.1f,    //  FQ    17
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
         0.5f, -0.8f,  0.3f,   0.0f, 0.0f, 1.0f,        0.7f,  0.2f,    //  FR    18
         0.5f, -0.8f,  0.3f,   0.0f, 0.0f, 1.0f,        0.7f,  0.2f,    //  FR    18
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.6f, -0.8f,  0.3f,   0.0f, 0.0f, 1.0f,        0.25f, 0.15f,   //  FS    19
        -0.6f, -0.8f,  0.3f,   0.0f, 0.0f, 1.0f,        0.25f, 0.15f,   //  FS    19
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.7f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.2f,  0.0f,    //  FT    20
        -0.7f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.2f,  0.0f,    //  FT    20
         0.0f,  0.0f,  0.3f,   0.0f, 0.0f, 1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f, -0.9f,  0.3f,   0.0f, 0.0f, 1.0f,        0.1f,  0.1f,    //  FA    1

        // Left Side
        -0.9f, -0.9f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.1f,    //  FA    1
        -0.9f, -0.6f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.2f,    //  FB    2
        -0.9f, -0.9f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.1f,    //  FA    22
        -0.9f, -0.9f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.1f,    //  FA    22
        -0.9f, -0.6f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.2f,    //  FB    23
        -0.9f, -0.6f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.2f,    //  FB    2
        -0.9f, -0.6f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.2f,    //  FB    2
        -0.8f, -0.5f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.25f, 0.25f,   //  FC    3
        -0.9f, -0.6f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.2f,    //  FB    23
        -0.9f, -0.6f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.2f,    //  FB    23
        -0.8f, -0.5f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.25f, 0.25f,   //  FC    24
        -0.8f, -0.5f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.25f, 0.25f,   //  FC    3
        -0.8f, -0.5f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.25f, 0.25f,   //  FC    3
        -0.8f, -0.4f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.3f,  0.3f,    //  FD    4
        -0.8f, -0.5f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.25f, 0.25f,   //  FC    24
        -0.8f, -0.5f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.25f, 0.25f,   //  FC    24
        -0.8f, -0.4f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.3f,  0.3f,    //  FD    25
        -0.8f, -0.4f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.3f,  0.3f,    //  FD    4
        -0.8f, -0.4f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.3f,  0.3f,    //  FD    4
        -0.9f, -0.2f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.4f,    //  FE    5
        -0.8f, -0.4f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.3f,  0.3f,    //  FD    25
        -0.8f, -0.4f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.3f,  0.3f,    //  FD    25
        -0.9f, -0.2f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.4f,    //  FE    26
        -0.9f, -0.2f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.4f,    //  FE    5
        -0.9f, -0.2f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.4f,    //  FE    5
        -0.9f,  0.2f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.6f,    //  FF    6
        -0.9f, -0.2f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.4f,    //  FE    26
        -0.9f, -0.2f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.4f,    //  FE    26
        -0.9f,  0.2f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.6f,    //  FF    27
        -0.9f,  0.2f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.6f,    //  FF    6
        -0.9f,  0.2f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.6f,    //  FF    6
        -0.8f,  0.4f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.7f,    //  FG    7
        -0.9f,  0.2f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.6f,    //  FF    27
        -0.9f,  0.2f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.05f, 0.6f,    //  FF    27
        -0.8f,  0.4f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.7f,    //  FG    28
        -0.8f,  0.4f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.7f,    //  FG    7
        -0.8f,  0.4f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.7f,    //  FG    7
        -0.8f,  0.5f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.75f,   //  FH    8
        -0.8f,  0.4f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.7f,    //  FG    28
        -0.8f,  0.4f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.7f,    //  FG    28
        -0.8f,  0.5f, -0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.75f,   //  FH    29
        -0.8f,  0.5f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.75f,   //  FH    8
        -0.8f,  0.5f,  0.3f,    -1.0f, 0.0f,  0.0f,        0.1f,  0.75f,   //  FH    8

        // Top
        -0.3f,  0.7f,  0.3f,    0.0f,  1.0f, 0.0f,        0.35f, 0.85f,   //  FI    9
        -0.8f,  0.5f, -0.3f,    0.0f,  1.0f, 0.0f,        0.1f,  0.75f,   //  FH    29
        -0.8f,  0.5f, -0.3f,    0.0f,  1.0f, 0.0f,        0.1f,  0.75f,   //  FH    29
        -0.3f,  0.7f, -0.3f,    0.0f,  1.0f, 0.0f,        0.35f, 0.85f,   //  FI    30
        -0.3f,  0.7f,  0.3f,    0.0f,  1.0f, 0.0f,        0.35f, 0.85f,   //  FI    9
        -0.3f,  0.7f,  0.3f,    0.0f,  1.0f, 0.0f,        0.35f, 0.85f,   //  FI    9
         0.4f,  0.8f,  0.3f,    0.0f,  1.0f, 0.0f,        0.7f,  0.9f,    //  FJ    10
        -0.3f,  0.7f, -0.3f,    0.0f,  1.0f, 0.0f,        0.35f, 0.85f,   //  FI    30
        -0.3f,  0.7f, -0.3f,    0.0f,  1.0f, 0.0f,        0.35f, 0.85f,   //  FI    30
         0.4f,  0.8f, -0.3f,    0.0f,  1.0f, 0.0f,        0.7f,  0.9f,    //  FJ    31
         0.4f,  0.8f,  0.3f,    0.0f,  1.0f, 0.0f,        0.7f,  0.9f,    //  FJ    10
         0.4f,  0.8f,  0.3f,    0.0f,  1.0f, 0.0f,        0.7f,  0.9f,    //  FJ    10 
         0.9f,  0.6f,  0.3f,    0.0f,  1.0f, 0.0f,        0.8f,  0.8f,    //  FK    11
         0.4f,  0.8f, -0.3f,    0.0f,  1.0f, 0.0f,        0.7f,  0.9f,    //  FJ    31
         0.4f,  0.8f, -0.3f,    0.0f,  1.0f, 0.0f,        0.7f,  0.9f,    //  FJ    31
         0.9f,  0.6f, -0.3f,    0.0f,  1.0f, 0.0f,        0.8f,  0.8f,    //  FK    32
         0.9f,  0.6f,  0.3f,    0.0f,  1.0f, 0.0f,        0.8f,  0.8f,    //  FK    11
         0.9f,  0.6f,  0.3f,    0.0f,  1.0f, 0.0f,        0.8f,  0.8f,    //  FK    11
         0.9f,  0.5f,  0.3f,    0.0f,  1.0f, 0.0f,        0.9f,  0.8f,    //  FL    12
         0.9f,  0.6f, -0.3f,    0.0f,  1.0f, 0.0f,        0.8f,  0.8f,    //  FK    32
         0.9f,  0.6f, -0.3f,    0.0f,  1.0f, 0.0f,        0.8f,  0.8f,    //  FK    32

        // Right Side
         0.9f,  0.5f, -0.3f,    1.0f, 0.0f, 0.0f,        0.9f,  0.8f,    //  FL    33
         0.9f,  0.5f,  0.3f,    1.0f, 0.0f, 0.0f,        0.9f,  0.8f,    //  FL    12
         0.9f,  0.5f,  0.3f,    1.0f, 0.0f, 0.0f,        0.9f,  0.8f,    //  FL    12
         0.8f,  0.4f,  0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.7f,    //  FM    13
         0.9f,  0.5f, -0.3f,    1.0f, 0.0f, 0.0f,        0.9f,  0.8f,    //  FL    33
         0.9f,  0.5f, -0.3f,    1.0f, 0.0f, 0.0f,        0.9f,  0.8f,    //  FL    33
         0.8f,  0.4f, -0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.7f,    //  FM    34
         0.8f,  0.4f,  0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.7f,    //  FM    13
         0.8f,  0.4f,  0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.7f,    //  FM    13
         0.8f, -0.3f,  0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.35f,   //  FN    14
         0.8f,  0.4f, -0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.7f,    //  FM    34
         0.8f,  0.4f, -0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.7f,    //  FM    34
         0.8f, -0.3f, -0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.35f,   //  FN    35
         0.8f, -0.3f,  0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.35f,   //  FN    14
         0.8f, -0.3f,  0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.35f,   //  FN    14
         0.9f, -0.5f,  0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.3f,    //  FO    15
         0.8f, -0.3f, -0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.35f,   //  FN    35
         0.8f, -0.3f, -0.3f,    1.0f, 0.0f, 0.0f,        0.85f, 0.35f,   //  FN    35
         0.9f, -0.5f, -0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.3f,    //  FO    36
         0.9f, -0.5f,  0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.3f,    //  FO    15
         0.9f, -0.5f,  0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.3f,    //  FO    15
         0.9f, -0.9f,  0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.1f,    //  FP    16
         0.9f, -0.5f, -0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.3f,    //  FO    36
         0.9f, -0.5f, -0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.3f,    //  FO    36
         0.9f, -0.9f, -0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.1f,    //  FP    37
         0.9f, -0.9f,  0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.1f,    //  FP    16.
         0.9f, -0.9f,  0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.1f,    //  FP    16
         0.6f, -0.9f,  0.3f,    1.0f, 0.0f, 0.0f,        0.8f,  0.1f,    //  FQ    17
         0.9f, -0.9f, -0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.1f,    //  FP    37
         0.9f, -0.9f, -0.3f,    1.0f, 0.0f, 0.0f,        0.95f, 0.1f,    //  FP    37

        // Bottom
         0.6f, -0.9f, -0.3f,    0.0f, -1.0f, 0.0f,        0.8f,  0.1f,    //  FQ    38
         0.6f, -0.9f,  0.3f,    0.0f, -1.0f, 0.0f,        0.8f,  0.1f,    //  FQ    17
         0.6f, -0.9f,  0.3f,    0.0f, -1.0f, 0.0f,        0.8f,  0.1f,    //  FQ    17
         0.5f, -0.8f,  0.3f,    0.0f, -1.0f, 0.0f,        0.7f,  0.2f,    //  FR    18
         0.6f, -0.9f, -0.3f,    0.0f, -1.0f, 0.0f,        0.8f,  0.1f,    //  FQ    38
         0.6f, -0.9f, -0.3f,    0.0f, -1.0f, 0.0f,        0.8f,  0.1f,    //  FQ    38
         0.5f, -0.8f, -0.3f,    0.0f, -1.0f, 0.0f,        0.7f,  0.2f,    //  FR    39
         0.5f, -0.8f,  0.3f,    0.0f, -1.0f, 0.0f,        0.7f,  0.2f,    //  FR    18

        // Back
         0.5f, -0.8f,  0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.2f,    //  FR    18
        -0.6f, -0.8f,  0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.15f,   //  FS    19
         0.5f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.2f,    //  FR    39
         0.5f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.2f,    //  FR    39
        -0.6f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.2f,    //  FS    40
        -0.6f, -0.8f,  0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.15f,   //  FS    19
        -0.6f, -0.8f,  0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.15f,   //  FS    19
        -0.7f, -0.9f,  0.3f,    0.0f, 0.0f, -1.0f,        0.2f,  0.0f,    //  FT    20
        -0.6f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.2f,    //  FS    40
        -0.6f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.2f,    //  FS    40
        -0.7f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.2f,  0.0f,    //  FT    41
        -0.7f, -0.9f,  0.3f,    0.0f, 0.0f, -1.0f,        0.2f,  0.0f,    //  FT    20
        -0.7f, -0.9f,  0.3f,    0.0f, 0.0f, -1.0f,        0.2f,  0.0f,    //  FT    20
        -0.9f, -0.9f,  0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.1f,    //  FA    1
         0.8f, -0.3f, -0.3f,    0.0f, 0.0f, -1.0f,        0.85f, 0.35f,   //  FN    35
        -0.9f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.1f,    //  FA    1
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f, -0.6f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.2f,    //  FB    2
        -0.9f, -0.6f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.2f,    //  FB    2
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f, -0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.25f,   //  FC    3
        -0.8f, -0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.25f,   //  FC    3
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f, -0.4f, -0.3f,    0.0f, 0.0f, -1.0f,        0.3f,  0.3f,    //  FD    4
        -0.8f, -0.4f, -0.3f,    0.0f, 0.0f, -1.0f,        0.3f,  0.3f,    //  FD    4
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f, -0.2f, -0.3f,    0.0f, 0.0f, -1.0f,        0.05f, 0.4f,    //  FE    5
        -0.9f, -0.2f, -0.3f,    0.0f, 0.0f, -1.0f,        0.05f, 0.4f,    //  FE    5
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f,  0.2f, -0.3f,    0.0f, 0.0f, -1.0f,        0.05f, 0.6f,    //  FF    6
        -0.9f,  0.2f, -0.3f,    0.0f, 0.0f, -1.0f,        0.05f, 0.6f,    //  FF    6
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f,  0.4f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.7f,    //  FG    7
        -0.8f,  0.4f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.7f,    //  FG    7
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.8f,  0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.75f,   //  FH    8
        -0.8f,  0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.75f,   //  FH    8
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.3f,  0.7f, -0.3f,    0.0f, 0.0f, -1.0f,        0.35f, 0.85f,   //  FI    9
        -0.3f,  0.7f, -0.3f,    0.0f, 0.0f, -1.0f,        0.35f, 0.85f,   //  FI    9
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.4f,  0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.9f,    //  FJ    10
         0.4f,  0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.9f,    //  FJ    10
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f,  0.6f, -0.3f,    0.0f, 0.0f, -1.0f,        0.8f,  0.8f,    //  FK    11
         0.9f,  0.6f, -0.3f,    0.0f, 0.0f, -1.0f,        0.8f,  0.8f,    //  FK    11
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f,  0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.9f,  0.8f,    //  FL    12
         0.9f,  0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.9f,  0.8f,    //  FL    12
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.8f,  0.4f, -0.3f,    0.0f, 0.0f, -1.0f,        0.85f, 0.7f,    //  FM    13
         0.8f,  0.4f, -0.3f,    0.0f, 0.0f, -1.0f,        0.85f, 0.7f,    //  FM    13
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.8f, -0.3f, -0.3f,    0.0f, 0.0f, -1.0f,        0.85f, 0.35f,   //  FN    14
         0.8f, -0.3f, -0.3f,    0.0f, 0.0f, -1.0f,        0.85f, 0.35f,   //  FN    14
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f, -0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.95f, 0.3f,    //  FO    15
         0.9f, -0.5f, -0.3f,    0.0f, 0.0f, -1.0f,        0.95f, 0.3f,    //  FO    15
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.9f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.95f, 0.1f,    //  FP    16
         0.9f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.95f, 0.1f,    //  FP    16
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.6f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.8f,  0.1f,    //  FQ    17
         0.6f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.8f,  0.1f,    //  FQ    17
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
         0.5f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.2f,    //  FR    18
         0.5f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.7f,  0.2f,    //  FR    18
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.6f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.15f,   //  FS    19
        -0.6f, -0.8f, -0.3f,    0.0f, 0.0f, -1.0f,        0.25f, 0.15f,   //  FS    19
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.7f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.2f,  0.0f,    //  FT    20
        -0.7f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.2f,  0.0f,    //  FT    20
         0.0f,  0.0f, -0.3f,    0.0f, 0.0f, -1.0f,        0.5f,  0.5f,    //  FCP   0
        -0.9f, -0.9f, -0.3f,    0.0f, 0.0f, -1.0f,        0.1f,  0.1f,    //  FA    1
};