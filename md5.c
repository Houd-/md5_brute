/*
 *  MD5 Brute Force
 *  Copyright (c) Houd <houd@houdhacks.info> 2014
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

char* hash;
char* wordlist;

int process_args(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("MD5 Brute Force - Usage:\n");
		printf("./md5_brute -h <hash> -w <wordlist>");
		goto exit;
	}
	if (process_args(argc, argv) == -1)
		goto halt;
	return 0;
	halt: printf("An error occured.");
	return -1;
	exit: return -1;
}

int process_args(int argc, char* argv[]) {
	if (argc < 5) {
		return -1;
	}
	for (int i; i < (argc - 1); i++) {
		if (strcmp(argv[i], "-h")) {
			i++;
			hash = argv[i];
			printf("Hash: %s\n",hash);
		} else if (strcmp(argv[i], "-w")) {
			i++;
			wordlist = argv[i];
			printf("Using list: %s\n",wordlist);
		}
	}
	return 0;
}
