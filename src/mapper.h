/*
 * mapper.h
 *
 *  Created on: Mar 24, 2016
 *      Author: howen
 */

#ifndef MAPPER_H_
#define MAPPER_H_

#include "reftools.h"
#include "readtools.h"
#include "utils.h"
#include "indextools.h"
#include "filter.h"
#include "verifier.h"

extern int window_size;
extern int step_size;
extern int edit_distance;
extern int cpu_thread_num;
extern int additional_gram_num;
extern int finished_thread_num;

extern uint32_t candidate_num_without_add_filter[256];
extern uint32_t mapped_read_num[256];
extern uint32_t candidate_num[256];
extern uint32_t mapping_num[256];
extern uint32_t read_count[256];
extern uint32_t (*novelCandidateGenerator)(const Read *read, const int rc, uint32_t **candidates,uint32_t **swapCandidates,uint32_t *maxCandiNum,TwoTuple **candis, TwoTuple **tempCandis, uint32_t *tupleNum,uint32_t *candiNumWithoutAddFilter);

void initMapper();
void finalizeMapper();
int CPUMap(int threadID);
void *startCPUThread(void *arg);
void *startSingleReadQueueThread(void *arg);
void *startOutputQueueThread(void *arg);

#endif /* MAPPER_H_ */
