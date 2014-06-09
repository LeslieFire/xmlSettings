/*
 *  utils.h
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
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;


void	ofEnableDataPath();
void	ofDisableDataPath();
string 	ofToDataPath(string path, bool absolute=false);

//set the root path that ofToDataPath will use to search for files relative to the app
//the path must have a trailing slash (/) !!!!
void	ofSetDataPathRoot( string root );

int ofToInt(const string& intString);
char ofToChar(const string& charString);
float ofToFloat(const string& floatString);
bool ofToBool(const string& boolString);

template <class T>
string ofToString(const T& value){
	ostringstream out;
	out << value;
	return out.str();
}

template <class T>
string ofToString(const T& value, int precision){
	ostringstream out;
	out << fixed << setprecision(precision) <<value;
	return out.str();
}

template <class T>
string ofToString(const T& value, int width, char fill){
	ostringstream out;
	out << fixed << setfill(fill) << setw(width) << value;
	return out.str();
}

/// like sprintf "%04.2d" or "%04.2f" format, in this example precision=2, width=4, fill='0'
template <class T>
string ofToString(const T& value, int precision, int width, char fill ){
	ostringstream out;
	out << fixed << setfill(fill) << setw(width) << setprecision(precision) << value;
	return out.str();
}
