/**
 * \file api.h
 * \author Petr Velan <petr.velan@cesnet.cz>
 * \author Lukas Hutak <lukas.hutak@cesnet.cz>
 * \brief Definitions for API functions
 * \date 2016
 */

/* Copyright (C) 2016 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is, and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */

#ifndef API_H
#define	API_H

#include <stdint.h>

/**
 * \defgroup ipxAPIDefinition API defintions
 * \ingroup publicAPIs
 * \brief Definitions for API functions
 *
 * @{
 */

/**
 * \def API
 * \brief Make an interface public outsite
 *
 * If the compiler supports attribute to mark objects as hidden, mark all
 * objects as hidden and export only objects explicitly marked to be part of
 * the public API.
 */
#define API __attribute__((visibility("default")))

/**
 * \def   IPX_API_MAJOR_VERSION
 * \brief API major version
 *
 * The version MUST be incremented if any backwards incompatible changes are
 * introduced to the public API. It MAY include minor and patch level changes.
 * Patch and minor version MUST be reset to 0 when major version is incremented.
 */
#define IPX_API_MAJOR_VERSION (2U) //(@IPFIXcol_VERSION_MAJOR@)

/**
 * \def   IPX_API_MINOR_VERSION
 * \brief API minor version
 *
 * The version MUST be incremented if new, backwards compatible functionality
 * is introduced to the public API. It MUST be incremented if any public API
 * functionality is marked as deprecated. Patch version MUST be reset to 0 when
 * minor version is incremented.
 */
#define IPX_API_MINOR_VERSION (0U) //(@IPFIXcol_VERSION_MINOR@)

/**
 * \def   IPX_API_PATCH_VERSION
 * \brief API patch version
 *
 * The version MUST be incremented if only backwards compatible bug fixes are
 * introduced. A bug fix is defined as an internal change that fixes incorrect
 * behavior.
 */
#define IPX_API_PATCH_VERSION (0U) // (@@IPFIXcol_VERSION_PATCH@@)

/**
 * \def   IPX_API_VERSION
 * \brief Public API definition
 *
 * Version of IPFIXcol API used during a plugin compilation. It is used to
 * verify compatibility when loading the plugin into the IPFIXcol.
 */
#define IPX_API_VERSION \
	API static const uint16_t ipx_api_major_version __attribute__((used)) = \
		IPX_API_MAJOR_VERSION; \
	API static const uint16_t ipx_api_minor_version __attribute__((used)) = \
		IPX_API_MINOR_VERSION; \
	API static const uint16_t ipx_api_patch_version __attribute__((used)) = \
		IPX_API_PATCH_VERSION;

/**@}*/

#endif	/* API_H */
