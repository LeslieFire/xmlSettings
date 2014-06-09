xmlSettings
===========

An addon that can make it easy to read and write configure files. It's extracted from ofxXmlSettings, but independent of openframeworks.

Examples
===========
First, create directory 'data' under bin directory;
Sencond, do as follows:

  xmlSettings xml;
  if (xml.loadFile("setting.xml")){
		param1 = xml.getValue("setting:param1", param1);
		
	}else{
		xml.setValue("setting:param1", param1);
		xml.saveFile("setting.xml");
	}
	
That's all !

The value can be int , float , string etc.
