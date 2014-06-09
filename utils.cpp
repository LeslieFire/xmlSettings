/*
 *  utils.cpp
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

#include "utils.h"

#include <direct.h>


static bool enableDataPath = true;


//--------------------------------------------------
void ofEnableDataPath(){
	enableDataPath = true;
}

//--------------------------------------------------
void ofDisableDataPath(){
	enableDataPath = false;
}

//--------------------------------------------------
//use ofSetDataPathRoot() to override this
static string & dataPathRoot(){

	static string * dataPathRoot = new string("data/");
	return *dataPathRoot;
}

static bool & isDataPathSet(){
	static bool * dataPathSet = new bool(false);
	return * dataPathSet;
}

//--------------------------------------------------
void ofSetDataPathRoot(string newRoot){
	string newPath = "";
	
	dataPathRoot() = newRoot;
	isDataPathSet() = true;
}

//--------------------------------------------------
string ofToDataPath(string path, bool makeAbsolute){

	if (!isDataPathSet())
		ofSetDataPathRoot(dataPathRoot());

	if( enableDataPath ){

		//check if absolute path has been passed or if data path has already been applied
		//do we want to check for C: D: etc ?? like  substr(1, 2) == ':' ??
		if( path.length()==0 || (path.substr(0,1) != "/" &&  path.substr(1,1) != ":" &&  path.substr(0,dataPathRoot().length()) != dataPathRoot())){
			path = dataPathRoot()+path;
		}

		if(makeAbsolute && (path.length()==0 || path.substr(0,1) != "/")){

			char currDir[1024];
			path = "\\"+path;
			path = _getcwd(currDir, 1024)+path;
		}

	}
	return path;
}

int ofToInt(const string & intString){
	int x = 0;
	istringstream cur(intString);
	cur >> x;
	return x;
}

float ofToFloat(const string & floatString){
	float x = 0.0f;
	istringstream cur(floatString);
	cur >> x;
	return x;
}

bool ofToBool(const string & boolString){
	static const string trueString = "true";
	static const string falseString = "false";
	string lower = boolString;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	if ( lower == trueString){
		return true;
	}
	if ( lower == falseString ){
		return false;
	}

	bool x = false;
	istringstream cur(lower);
	cur >> x; 
	return x;
}

char ofToChar(const string & charString){
	char x = '\0';
	istringstream cur(charString);
	cur >> x;
	return x;
}