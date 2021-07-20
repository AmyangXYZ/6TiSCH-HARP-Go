#ifndef HARP_H
#define HARP_H

// hierarchical respource partitioning

#include <stdlib.h>
#include <stdio.h>

#define MAX_CHANNEL 8
#define MAX_CHILDREN_NUM 6
#define MAX_HOP 5

typedef struct
{
    uint8_t ts;
    uint8_t ch;
} HARP_interface_t;

typedef struct
{
    uint8_t ts_start;
    uint8_t ts_end;
    uint8_t ch_start;
    uint8_t ch_end;
} HARP_subpartition_t;

typedef struct
{
    uint8_t id;
    HARP_interface_t iface[MAX_HOP];
    HARP_subpartition_t sp_rel[MAX_HOP];
    HARP_subpartition_t sp_abs[MAX_HOP];
} HARP_child_t;

typedef struct
{
    HARP_interface_t iface[MAX_HOP];
    HARP_subpartition_t sp_abs[MAX_HOP];
} HARP_self_t;

typedef struct __HARP_skyline_t
{
    uint8_t start;
    uint8_t end;
    uint8_t width;
    uint8_t height;
    struct __HARP_skyline_t *prev;
    struct __HARP_skyline_t *next;
} HARP_skyline_t;

uint8_t interfaceComposition();
uint8_t subpartitionAllocation();

#endif