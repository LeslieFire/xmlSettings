/*
 *  xmlSettings.h
 *
 *  Created by Leslie Yang on 06/09/14.
 *  Copyright 2014 https://github.com/LeslieFire All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the author nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 *  OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *  OF THE POSSIBILITY OF SUCH DAMAGE.
 *s
 *  ************************************************************************************ */ 
#pragma once

#include <iostream>
#include "string.h"
#include "tinyxml.h"

using namespace std;

#define MAX_TAG_VALUE_LENGTH_IN_CHARS		1024

class xmlSettings{

public:
	xmlSettings();
	xmlSettings(const string& xmlFile);

	~xmlSettings();

	void setVerbose(bool _verbose);

	bool loadFile(const string& xmlFile);
	bool saveFile(const string& xmlFile);
	bool saveFile();


	int 	getValue(const string&  tag, int            defaultValue, int which = 0);
	double 	getValue(const string&  tag, double         defaultValue, int which = 0);
	string 	getValue(const string&  tag, const string& 	defaultValue, int which = 0);

	int 	setValue(const string&  tag, int            value, int which = 0);
	int 	setValue(const string&  tag, double         value, int which = 0);
	int 	setValue(const string&  tag, const string& 	value, int which = 0);

	TiXmlDocument	doc;
	bool			bDocLoaded;

protected:
	TiXmlHandle		storedHandle;
	int level;

	bool 	readTag(const string&  tag, TiXmlHandle& valHandle, int which = 0);	// max 1024 chars...
	int 	writeTag(const string&  tag, const string& valueString, int which = 0);
};