/*
    This file is part of Kismet

    Kismet is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Kismet is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kismet; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "config.h"

#ifndef __NL80211_CONFIG__
#define __NL80211_CONFIG__

struct mac80211_channel_block {
	string phyname;
	vector<unsigned int> channel_list;
};

int mac80211_connect(const char *interface, void **handle, void **cache,
					 void **family, char *errstr);
void mac80211_disconnect(void *handle);

// Make a vap under mac80211
int mac80211_createvap(const char *interface, const char *newinterface, char *errstr);

// Set channel using nl80211 instead of SIOCWCHAN
int mac80211_setchannel(const char *interface, int channel, 
						unsigned int chmode, char *errstr);
int mac80211_setchannel_cache(const char *interface, void *handle,
							  void *family, int channel,
							  unsigned int chmode, char *errstr);

string mac80211_find_parent(const char *interface);

vector<unsigned int>  mac80211_get_chanlist(const char *interface, char *errstr);

#endif


