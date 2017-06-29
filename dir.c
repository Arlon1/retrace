/*
 * Copyright (c) 2017, [Ribose Inc](https://www.ribose.com).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "common.h"
#include "dir.h"

DIR *RETRACE_IMPLEMENTATION(opendir)(const char *dirname)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_STRING,  PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirname};
	DIR *dirp = NULL;


	event_info.function_name = "opendir";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_DIR;
	event_info.return_value = &dirp;
	retrace_log_and_redirect_before(&event_info);

	dirp = real_opendir(dirname);

	retrace_log_and_redirect_after(&event_info);

	return dirp;
}

RETRACE_REPLACE(opendir, DIR *, (const char *dirname), (dirname))


int RETRACE_IMPLEMENTATION(closedir)(DIR *dirp)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_DIR, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirp};
	int r;


	event_info.function_name = "closedir";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_INT;
	event_info.return_value = &r;
	retrace_log_and_redirect_before(&event_info);

	r = real_closedir(dirp);

	retrace_log_and_redirect_after(&event_info);

	return (r);
}

RETRACE_REPLACE(closedir, int, (DIR *dirp), (dirp))


DIR *RETRACE_IMPLEMENTATION(fdopendir)(int fd)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_INT, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&fd};
	DIR *dirp = NULL;


	event_info.function_name = "fdopendir";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_DIR;
	event_info.return_value = &dirp;
	retrace_log_and_redirect_before(&event_info);

	dirp = real_fdopendir(fd);

	retrace_log_and_redirect_after(&event_info);

	return (dirp);
}

RETRACE_REPLACE(fdopendir, DIR *, (int fd), (fd))


int RETRACE_IMPLEMENTATION(readdir_r)(DIR *dirp, struct dirent *entry, struct dirent **result)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_DIR, PARAMETER_TYPE_POINTER, PARAMETER_TYPE_POINTER, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirp, &entry, &result};
	int ret;


	event_info.function_name = "readdir_r";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_INT;
	event_info.return_value = &ret;
	retrace_log_and_redirect_before(&event_info);

	ret = real_readdir_r(dirp, entry, result);

	retrace_log_and_redirect_after(&event_info);

	return ret;
}

RETRACE_REPLACE(readdir_r, int,
	(DIR *dirp, struct dirent *entry, struct dirent **result),
	(dirp, entry, result))


long RETRACE_IMPLEMENTATION(telldir)(DIR *dirp)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_DIR, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirp};
	long offset;


	event_info.function_name = "telldir";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_INT;
	event_info.return_value = &offset;
	retrace_log_and_redirect_before(&event_info);

	offset = real_telldir(dirp);

	retrace_log_and_redirect_after(&event_info);

	return offset;
}

RETRACE_REPLACE(telldir, long, (DIR *dirp), (dirp))


void RETRACE_IMPLEMENTATION(seekdir)(DIR *dirp, long loc)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_DIR, PARAMETER_TYPE_INT, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirp, &loc};


	event_info.function_name = "seekdir";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_END;
	retrace_log_and_redirect_before(&event_info);

	real_seekdir(dirp, loc);

	retrace_log_and_redirect_after(&event_info);
}

RETRACE_REPLACE(seekdir, void, (DIR *dirp, long loc), (dirp, loc))


void RETRACE_IMPLEMENTATION(rewinddir)(DIR *dirp)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_DIR, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirp};


	event_info.function_name = "rewinddir";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_END;
	retrace_log_and_redirect_before(&event_info);

	real_rewinddir(dirp);

	retrace_log_and_redirect_after(&event_info);
}

RETRACE_REPLACE(rewinddir, void, (DIR *dirp), (dirp))


int RETRACE_IMPLEMENTATION(dirfd)(DIR *dirp)
{
	struct rtr_event_info event_info;
	unsigned int parameter_types[] = {PARAMETER_TYPE_DIR, PARAMETER_TYPE_END};
	void const *parameter_values[] = {&dirp};
	int dir_fd;


	event_info.function_name = "dirfd";
	event_info.parameter_types = parameter_types;
	event_info.parameter_values = (void **) parameter_values;
	event_info.return_value_type = PARAMETER_TYPE_INT;
	event_info.return_value = &dir_fd;
	retrace_log_and_redirect_before(&event_info);

	/* get dir fd */
	dir_fd = real_dirfd(dirp);

	retrace_log_and_redirect_after(&event_info);

	return dir_fd;
}

RETRACE_REPLACE(dirfd, int, (DIR *dirp), (dirp))
