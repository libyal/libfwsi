/*
 * Known folder identifier functions
 *
 * Copyright (C) 2010-2024, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFWSI_KNOWN_FOLDER_IDENTIFIER_H )
#define _LIBFWSI_KNOWN_FOLDER_IDENTIFIER_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The CLSID is stored as a little endian GUID
 */
typedef struct libfwsi_known_folder_identifier_definition libfwsi_known_folder_identifier_definition_t;

struct libfwsi_known_folder_identifier_definition
{
	/* The identifier
	 */
	uint8_t *identifier;

	/* The name
	 */
	const char *name;
};

extern uint8_t libfwsi_known_folder_identifier_3d_objects[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_accountpictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_addnewprogramsfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_administrative_tools[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appdata[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appdatadesktop[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appdatadocuments[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appdatafavorites[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appdataprogramdata[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_application_shortcuts[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appmods[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appsfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_appupdatesfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_cache[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_camera_roll[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_camerarolllibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_captures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_cd_burning[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_changeremoveprogramsfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_administrative_tools[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_appdata[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_desktop[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_documents[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_programs[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_start_menu[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_start_menu_places[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_startup[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_templates[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_commondownloads[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_commonmusic[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_commonpictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_commonringtones[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_commonvideo[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_conflictfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_connectionsfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_contacts[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_controlpanelfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_cookies[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_credentialmanager[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_cryptokeys[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_cscfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_default_gadgets[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_desktop[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_development_files[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_device_metadata_store[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_documentslibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_downloads[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_dpapikeys[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_favorites[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_fonts[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_gadgets[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_games[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_gametasks[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_history[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_homegroupcurrentuserfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_homegroupfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_implicitappshortcuts[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_internetfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_libraries[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_links[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_local_appdata[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_local_documents[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_local_downloads[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_local_music[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_local_pictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_local_videos[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_localappdatalow[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_localizedresourcesdir[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_mapifolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_musiclibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_my_music[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_my_pictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_my_video[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_mycomputerfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_nethood[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_networkplacesfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_oem_links[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_onedrive[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_onedrivecameraroll[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_onedrivedocuments[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_onedrivemusic[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_onedrivepictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_original_images[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_personal[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_photoalbums[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_pictureslibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_playlists[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_printersfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_printhood[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_profile[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programfiles[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programfilescommon[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programfilescommonx64[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programfilescommonx86[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programfilesx64[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programfilesx86[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_programs[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_public[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_publicaccountpictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_publicgametasks[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_publiclibraries[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_quick_launch[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_recent[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_recorded_calls[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_recordedtvlibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_recyclebinfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_resourcedir[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_retail_demo[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_ringtones[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_roamed_tile_images[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_roaming_tiles[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_samplemusic[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_samplepictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_sampleplaylists[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_samplevideos[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_savedgames[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_savedpictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_savedpictureslibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_screenshots[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_searches[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_searchhistoryfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_searchhomefolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_searchtemplatesfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_sendto[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_start_menu[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_startmenuallprograms[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_startup[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_synccenterfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_syncresultsfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_syncsetupfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_system[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_systemcertificates[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_systemx86[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_templates[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_thisdevicefolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_thispcdesktopfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_treepropertiesfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_user_pinned[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_userprofiles[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_userprogramfiles[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_userprogramfilescommon[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_usersfilesfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_userslibrariesfolder[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_videoslibrary[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_windows[ 16 ];

extern uint8_t libfwsi_known_folder_identifier_unknown[ 16 ];

LIBFWSI_EXTERN \
const char *libfwsi_known_folder_identifier_get_name(
             const uint8_t *known_folder_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_KNOWN_FOLDER_IDENTIFIER_H ) */

