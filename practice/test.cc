#include <stdio.h>
#include <stdlib.h>
#include <isa-l.h>

#define DATA_BLOCKS 4
#define PARITY_BLOCKS 2
#define TOTAL_BLOCKS (DATA_BLOCKS + PARITY_BLOCKS)
#define BLOCK_SIZE 4096

int main() {
    // 初始化数据
    unsigned char *data[TOTAL_BLOCKS];
    unsigned char *coding[TOTAL_BLOCKS];
    unsigned char *recover[TOTAL_BLOCKS];
    int i, j;
    for (i = 0; i < TOTAL_BLOCKS; i++) {
        data[i] = (unsigned char *)malloc(BLOCK_SIZE);
        coding[i] = (unsigned char *)malloc(BLOCK_SIZE);
        recover[i] = (unsigned char *)malloc(BLOCK_SIZE);
        for (j = 0; j < BLOCK_SIZE; j++) {
            data[i][j] = rand() % 256;
        }
    }

    // 初始化编码/解码库
    struct ec_args args;
    args.k = DATA_BLOCKS;
    args.m = TOTAL_BLOCKS;
    args.w = 8; // 字节大小
    ec_init();

    // 编码数据
    ec_encode_data(BLOCK_SIZE, args.k, args.m - args.k, data, coding);

    // 模拟数据丢失
    data[0] = NULL;

    // 恢复丢失的数据
    ec_decode_data(BLOCK_SIZE, args.k, args.m - args.k, coding, recover);

    // 检查恢复的数据是否正确
    for (i = 0; i < TOTAL_BLOCKS; i++) {
        if (data[i] != NULL) {
            for (j = 0; j < BLOCK_SIZE; j++) {
                if (recover[i][j] != data[i][j]) {
                    printf("Recovered data does not match original data.\n");
                    return 1;
                }
            }
        }
    }

    printf("Data recovery successful.\n");

    // 释放内存
    for (i = 0; i < TOTAL_BLOCKS; i++) {
        free(data[i]);
        free(coding[i]);
        free(recover[i]);
    }

    return 0;
}
