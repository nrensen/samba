/*
   Unix SMB/CIFS implementation.
   Authentication utility functions
   Copyright (C) Volker Lendecke 2010

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

#ifndef _RPC_CLIENT_UTIL_NETLOGON_H_
#define _RPC_CLIENT_UTIL_NETLOGON_H_

/* The following definitions come from rpc_client/util_netlogon.c  */

NTSTATUS copy_netr_SamBaseInfo(TALLOC_CTX *mem_ctx,
			       const struct netr_SamBaseInfo *in,
			       struct netr_SamBaseInfo *out);
NTSTATUS copy_netr_SamInfo3(TALLOC_CTX *mem_ctx,
			    const struct netr_SamInfo3 *in,
			    struct netr_SamInfo3 **pout);
NTSTATUS map_validation_to_info3(TALLOC_CTX *mem_ctx,
				 uint16_t validation_level,
				 union netr_Validation *validation,
				 struct netr_SamInfo3 **info3_p);
NTSTATUS copy_netr_SamInfo6(TALLOC_CTX *mem_ctx,
			    const struct netr_SamInfo6 *in,
			    struct netr_SamInfo6 **pout);
NTSTATUS map_validation_to_info6(TALLOC_CTX *mem_ctx,
				 uint16_t validation_level,
				 union netr_Validation *validation,
				 struct netr_SamInfo6 **info6_p);
NTSTATUS map_info3_to_validation(TALLOC_CTX *mem_ctx,
				 struct netr_SamInfo3 *info3,
				 uint16_t *_validation_level,
				 union netr_Validation **_validation);
NTSTATUS map_info6_to_validation(TALLOC_CTX *mem_ctx,
				 const struct netr_SamInfo6 *info6,
				 uint16_t *_validation_level,
				 union netr_Validation **_validation);
NTSTATUS copy_netr_DsRGetDCNameInfo(TALLOC_CTX *mem_ctx,
				    const struct netr_DsRGetDCNameInfo *in,
				    struct netr_DsRGetDCNameInfo **pout);

#endif /* _RPC_CLIENT_UTIL_NETLOGON_H_ */
