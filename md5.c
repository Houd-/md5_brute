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

int process_args(int argc, char* argv[]);

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("MD5 Brute Force - Usage:\n");
		printf("./md5_brute -h <hash> -w <wordlist>");
		goto exit;
	}
	return 0;
	exit:
	return -1;
}

int process_args(int argc, char* argv[]){
	return 0;
}
