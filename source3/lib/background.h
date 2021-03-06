/*
   Unix SMB/CIFS implementation.
   Regular background jobs as forked helpers
   Copyright (C) Volker Lendecke 2012

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _LIB_BACKGROUND_H_
#define _LIB_BACKGROUND_H_

#include "replace.h"
#include <tevent.h>
#include "libcli/util/ntstatus.h"

struct messaging_context;

/*
 * From a parent process regularly fork a process and execute fn(). fn()
 * returns the number of seconds to wait before it is run next time. Returning
 * -1 means stop the job.
 */

struct tevent_req *background_job_send(TALLOC_CTX *mem_ctx,
				       struct tevent_context *ev,
				       struct messaging_context *msg,
				       uint32_t *trigger_msgs,
				       size_t num_trigger_msgs,
				       time_t initial_wait_sec,
				       int (*fn)(void *private_data),
				       void *private_data);
NTSTATUS background_job_recv(struct tevent_req *req);

#endif
