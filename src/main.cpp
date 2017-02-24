//
// Created by hantongyang on 2017/2/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ip_str2unint(char *ip) {
    unsigned int int_ip;
    int len = strlen(ip);
    char ip_part[4];
    int part_num = 3;
    int index = 0;
    memset(ip_part, 0, 4);
    for (int i = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.') {
            int_ip = ((unsigned int) atoi(ip_part)) << (part_num * 8) ^ int_ip;
            part_num--;
            index = 0;
            memset(ip_part, 0, 4);
        } else {
            ip_part[index++] = ip[i];
        }
    }
    //处理最后一部分
    int_ip = ((unsigned int) atoi(ip_part)) << (part_num * 8) ^ int_ip;
    return int_ip;
}

char *itoa(int a) {
    char s[11] = "\0";
    int i = 0;
    while (a) {
        int r = a % 10;
        a /= 10;
        s[i++] = r + '0';
    }
    return strrev(s);
}

char *ip_unint2str(unsigned int ip, char *ip_str) {
    ip_str = (char *) malloc(16 * sizeof(char));
    memset(ip_str, '\0', 16 * sizeof(char));
    int part_num = 3;
    int index = 0;
    do {
        int tmp = (ip >> (part_num * 8)) & 0x000000ff;
        char *s = itoa(tmp);
        strcat(ip_str, s);
        strcat(ip_str, ".");
        /*for (int i = 0; s[i] != '\0'; i++) {
            ip_str[index++] = s[i];
        }
        ip_str[index++] = '.';*/
    } while (part_num--);
    //去掉最后一个.号
    ip_str[strlen(ip_str) - 1] = '\0';
    return ip_str;
}

int main() {
    char *ip = "192.168.1.1";
    printf("%u\n", ip_str2unint(ip));
    char *s = NULL;
    printf("%s", ip_unint2str(ip_str2unint(ip), s));
    return 0;
}
