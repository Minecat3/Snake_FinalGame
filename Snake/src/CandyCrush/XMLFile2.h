#pragma once

#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "GameScene.hh"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <XML\rapidxml.hpp>
#include <XML\rapidxml_iterators.hpp>
#include <XML\rapidxml_print.hpp>
#include <XML\rapidxml_utils.hpp>
#include <sstream>
#include <inttypes.h>
#include <errno.h>

using namespace rapidxml;
using namespace Logger;
using namespace std;

//READ COMMENTS ON "XMLFile.h"

void ReadXML2(int *cells, int* speed, int* snakeX, int*snakeY, int* timer) {

	xml_document<> doc;
	ifstream file("XMLFile.xml");
	stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	int i = 1;

	for (rapidxml::xml_node<> *pNode = pRoot->first_node("nivell"); pNode; pNode = pNode->next_sibling()) {
		rapidxml::xml_attribute<>*pAttr = pNode->first_attribute();
		if (i == 2) {
			for (rapidxml::xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				if (strcmp(pNodeI->name(), "cells") == 0) {
					*cells = strtoumax(pNodeI->value(), NULL, 10);
				}
				else if (strcmp(pNodeI->name(), "speed") == 0) {
					*speed = strtoumax(pNodeI->value(), NULL, 10);
				}
				else if (strcmp(pNodeI->name(), "snakeX") == 0) {
					*snakeX = strtoumax(pNodeI->value(), NULL, 10);
				}
				else if (strcmp(pNodeI->name(), "snakeY") == 0) {
					*snakeY = strtoumax(pNodeI->value(), NULL, 10);
				}
				else if (strcmp(pNodeI->name(), "timer") == 0) {
					*timer = strtoumax(pNodeI->value(), NULL, 10);
				}
			}
			return;
		}
		i++;
	}
}
