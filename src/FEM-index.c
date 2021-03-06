/*
 * FEM-index.c
 *
 *  Created on: Mar 23, 2016
 *      Author: haowen
 */

#include "FEM-index.h"

static int print_usage() {
    fprintf(stderr, "Usage: FEM index <window_size> <step_size> <ref>\n");
    return 1;
}

int index_main(int argc, char* argv[]) {
	if(argc < 4) {
        return print_usage();
	}

	window_size = atoi(argv[1]);
    step_size = atoi(argv[2]);
	ref_file_name = argv[3];
    /* TODO:add arguments check */ 

	initRef(&reference);

    char indexFileName[128];
    indexFileName[0] = '\0';
	strcpy(indexFileName, ref_file_name);
	sprintf(indexFileName + strlen(indexFileName), ".fem");
    index_file_name = indexFileName;
    char tmp_header_file_name[128];
    tmp_header_file_name[0] = '\0';
	strcpy(tmp_header_file_name, index_file_name);
	sprintf(tmp_header_file_name + strlen(tmp_header_file_name), ".header");
    header_file_name = tmp_header_file_name;

	double startTime = 0.0;

	initRefFile();
    startTime = realtime();
    getRef(&reference);
    fprintf(stderr, "Reference length: %u. Loaded into memory in %fs.\n", reference.lookupTable[reference.refNum], realtime() - startTime);

    startTime = realtime();
    init_saving_index();
    construct_index();
    save_index();
    fprintf(stderr, "Number of bases: %u, number of chromosomes: %d.\n Built index in %fs.\n", reference.lookupTable[reference.refNum], reference.refNum, realtime() - startTime);
    destroyRef(&reference);
    finalizeRefFile();
    finalize_saving_index();
	return 0;
}
