/*
 * Copyright 2013 gtalent2@gmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//Generated Code

#include <fstream>
#include "enginemodels.hpp"

using namespace models;
using namespace models::cyborgbear;

string models::cyborgbear::version = "1.0.0-beta10";

int Model::readJsonFile(string path) {
	std::ifstream in;
	in.open(cyborgbear::toCString(path));
	if (in.is_open()) {
		std::string json((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		in.close();
		return fromJson(cyborgbear::toString(json));
	}
	return cyborgbear::Error_CouldNotAccessFile;
}

void Model::writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs) {
	std::ofstream out;
	out.open(cyborgbear::toCString(path));
	std::string json = cyborgbear::toStdString(toJson(sttngs));
	out << json << "\0";
	out.close();
}

int Model::fromJson(string json) {
	cyborgbear::JsonValOut obj = cyborgbear::read(json);
	cyborgbear::Error retval = loadJsonObj(obj);
	cyborgbear::decref(obj);
	return retval;
}

string Model::toJson(cyborgbear::JsonSerializationSettings sttngs) {
	cyborgbear::JsonValOut val = buildJsonObj();
	cyborgbear::JsonObjOut obj = cyborgbear::toObj(val);
	return cyborgbear::write(obj, sttngs);
}

unknown::unknown() {
}

unknown::unknown(Model *v) {
	set(v);
}

unknown::unknown(bool v) {
	set(v);
}

unknown::unknown(int v) {
	set(v);
}

unknown::unknown(double v) {
	set(v);
}

unknown::unknown(string v) {
	set(v);
}

unknown::~unknown() {
}

cyborgbear::Error unknown::loadJsonObj(cyborgbear::JsonVal obj) {
	cyborgbear::JsonObjOut wrapper = cyborgbear::newJsonObj();
	cyborgbear::objSet(wrapper, "Value", obj);
	m_data = cyborgbear::write(wrapper, cyborgbear::Compact);
	if (cyborgbear::isBool(obj)) {
		m_type = cyborgbear::Bool;
	} else if (cyborgbear::isInt(obj)) {
		m_type = cyborgbear::Integer;
	} else if (cyborgbear::isDouble(obj)) {
		m_type = cyborgbear::Double;
	} else if (cyborgbear::isString(obj)) {
		m_type = cyborgbear::String;
	} else if (cyborgbear::isObj(obj)) {
		m_type = cyborgbear::Object;
	}

	if (cyborgbear::isNull(obj)) {
		return cyborgbear::Error_GenericParsingError;
	} else {
		return cyborgbear::Error_Ok;
	}
}

cyborgbear::JsonValOut unknown::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::read(m_data);
#ifdef CYBORGBEAR_USING_QT
	cyborgbear::JsonValOut val = cyborgbear::objRead(obj, "Value");
#else
	cyborgbear::JsonValOut val = cyborgbear::incref(cyborgbear::objRead(obj, "Value"));
#endif
	cyborgbear::decref(obj);
	return val;
}

bool unknown::loaded() {
	return m_data != "";
}

bool unknown::isBool() {
	return m_type == cyborgbear::Bool;
}

bool unknown::isInt() {
	return m_type == cyborgbear::Integer;
}

bool unknown::isDouble() {
	return m_type == cyborgbear::Double;
}

bool unknown::isString() {
	return m_type == cyborgbear::String;
}

bool unknown::isObject() {
	return m_type == cyborgbear::Object;
}

bool unknown::toBool() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toBool(out);
}

int unknown::toInt() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toInt(out);
}

double unknown::toDouble() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toDouble(out);
}

string unknown::toString() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toString(out);
}

void unknown::set(Model *v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = v->buildJsonObj();
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Object;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);

	unknown *unk = dynamic_cast<unknown*>(v);
	if (unk)
		m_type = unk->m_type;
}

void unknown::set(bool v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Bool;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(int v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Integer;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(double v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Double;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(string v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::String;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

#ifdef CYBORGBEAR_BOOST_ENABLED

void unknown::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string unknown::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}
	string str;
	while (out.good())
		str += out.get();
	return str;
}
#endif


#include "string.h"
#include "enginemodels.hpp"

using namespace models;
using std::stringstream;

CreatureType::CreatureType() {
	this->special = 0;
}

StatusEffect::StatusEffect() {
	this->attackerEffect = 0;
	this->enemyEffect = 0;
}

Fraction::Fraction() {
	this->current = 0;
	this->available = 0;
}

ModelFile::ModelFile() {
	this->type = "";
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Size::Size() {
	this->width = 0;
	this->height = 0;
}

Bounds::Bounds() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

SaveVariables::SaveVariables() {
}

SpriteSheetImage::SpriteSheetImage() {
}

SpriteSheet::SpriteSheet() {
	this->tilesWide = 0;
	this->tilesHigh = 0;
	this->tileWidth = 0;
	this->tileHeight = 0;
	this->srcFile = "";
	this->imageIdIterator = 0;
}

CreatureMove::CreatureMove() {
	this->type = "";
	this->power = 0;
	this->requiresRegarge = 0;
	this->script = "";
}

CreatureMoveInstance::CreatureMoveInstance() {
	this->creatureMove = 0;
}

Creature::Creature() {
	this->iD = 0;
	this->creatureClass = "";
	this->male = 0;
	this->level = 0;
	this->attack = 0;
	this->specAttack = 0;
	this->defense = 0;
	this->specDefense = 0;
	this->burned = 0;
	this->frozen = 0;
	this->poisoned = 0;
	this->asleep = 0;
}

User::User() {
	this->personID = 0;
	this->world = "";
	this->zone = "";
	this->xAddress = 0;
	this->yAddress = 0;
	this->layer = 0;
}

ZoneInstance::ZoneInstance() {
	this->accessorID = "";
	this->path = "";
}

ZoneHeader::ZoneHeader() {
	this->path = "";
}

SaveFile::SaveFile() {
}

Image::Image() {
	this->spriteSheet = "";
	this->imgId = 0;
}

World::World() {
}

AnimationSlide::AnimationSlide() {
	this->interval = 0;
}

Animation::Animation() {
}

AnimLayer::AnimLayer() {
}

CreatureClass::CreatureClass() {
	this->successor = "";
	this->predecessor = "";
}

PersonClass::PersonClass() {
	this->iD = 0;
}

TileClass::TileClass() {
	this->terrainFlags = 0;
	this->import = "";
}

Person::Person() {
}

Sprite::Sprite() {
	this->spriteType = 0;
	this->personID = 0;
	this->speed = 0;
	this->name = "";
	this->path = "";
	this->scriptPath = "";
}

Tile::Tile() {
}

Zone::Zone() {
}

cyborgbear::Error CreatureType::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Special");
		{
			if (cyborgbear::isBool(obj0)) {
				this->special = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "StrongAgainst");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->strongAgainst.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->strongAgainst[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "WeakAgainst");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->weakAgainst.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->weakAgainst[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error StatusEffect::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AttackerEffect");
		{
			if (cyborgbear::isInt(obj0)) {
				this->attackerEffect = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "EnemyEffect");
		{
			if (cyborgbear::isInt(obj0)) {
				this->enemyEffect = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Fraction::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Current");
		{
			if (cyborgbear::isInt(obj0)) {
				this->current = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Available");
		{
			if (cyborgbear::isInt(obj0)) {
				this->available = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ModelFile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Type");
		{
			if (cyborgbear::isString(obj0)) {
				this->type = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Point::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->x = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->y = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Size::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Bounds::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->x = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->y = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SaveVariables::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Vars");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						retval |= this->vars[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteSheetImage::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SrcBounds");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->srcBounds.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteSheet::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesWide");
		{
			if (cyborgbear::isInt(obj0)) {
				this->tilesWide = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesHigh");
		{
			if (cyborgbear::isInt(obj0)) {
				this->tilesHigh = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileWidth");
		{
			if (cyborgbear::isInt(obj0)) {
				this->tileWidth = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileHeight");
		{
			if (cyborgbear::isInt(obj0)) {
				this->tileHeight = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SrcFile");
		{
			if (cyborgbear::isString(obj0)) {
				this->srcFile = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					int i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->images[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ImageIdIterator");
		{
			if (cyborgbear::isInt(obj0)) {
				this->imageIdIterator = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "RecycledImageIds");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->recycledImageIds.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isInt(obj1)) {
							this->recycledImageIds[i] = cyborgbear::toInt(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error CreatureMove::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Type");
		{
			if (cyborgbear::isString(obj0)) {
				this->type = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Power");
		{
			if (cyborgbear::isInt(obj0)) {
				this->power = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "RequiresRegarge");
		{
			if (cyborgbear::isBool(obj0)) {
				this->requiresRegarge = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Script");
		{
			if (cyborgbear::isString(obj0)) {
				this->script = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Burn");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->burn.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Freeze");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->freeze.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Paralyze");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->paralyze.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Poison");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->poison.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Sleep");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->sleep.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error CreatureMoveInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CreatureMove");
		{
			if (cyborgbear::isInt(obj0)) {
				this->creatureMove = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PP");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->pP.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Creature::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->iD = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CreatureClass");
		{
			if (cyborgbear::isString(obj0)) {
				this->creatureClass = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Male");
		{
			if (cyborgbear::isBool(obj0)) {
				this->male = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Level");
		{
			if (cyborgbear::isInt(obj0)) {
				this->level = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Health");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->health.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Attack");
		{
			if (cyborgbear::isInt(obj0)) {
				this->attack = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpecAttack");
		{
			if (cyborgbear::isInt(obj0)) {
				this->specAttack = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Defense");
		{
			if (cyborgbear::isInt(obj0)) {
				this->defense = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpecDefense");
		{
			if (cyborgbear::isInt(obj0)) {
				this->specDefense = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Burned");
		{
			if (cyborgbear::isBool(obj0)) {
				this->burned = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Frozen");
		{
			if (cyborgbear::isBool(obj0)) {
				this->frozen = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Poisoned");
		{
			if (cyborgbear::isBool(obj0)) {
				this->poisoned = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Asleep");
		{
			if (cyborgbear::isBool(obj0)) {
				this->asleep = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Moves");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->moves.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->moves[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error User::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->personID = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "World");
		{
			if (cyborgbear::isString(obj0)) {
				this->world = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zone");
		{
			if (cyborgbear::isString(obj0)) {
				this->zone = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "XAddress");
		{
			if (cyborgbear::isInt(obj0)) {
				this->xAddress = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "YAddress");
		{
			if (cyborgbear::isInt(obj0)) {
				this->yAddress = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Layer");
		{
			if (cyborgbear::isInt(obj0)) {
				this->layer = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ZoneInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AccessorID");
		{
			if (cyborgbear::isString(obj0)) {
				this->accessorID = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Location");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->location.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ZoneHeader::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Size");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->size.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SaveFile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Vars");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						retval |= this->vars[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "User");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->user.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Image::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteSheet");
		{
			if (cyborgbear::isString(obj0)) {
				this->spriteSheet = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ImgId");
		{
			if (cyborgbear::isInt(obj0)) {
				this->imgId = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DefaultSize");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->defaultSize.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error World::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zones");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->zones.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->zones[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error AnimationSlide::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Interval");
		{
			if (cyborgbear::isInt(obj0)) {
				this->interval = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Image");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->image.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Animation::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->images.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->images[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error AnimLayer::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Point");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->point.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Animation");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->animation.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error CreatureClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Successor");
		{
			if (cyborgbear::isString(obj0)) {
				this->successor = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Predecessor");
		{
			if (cyborgbear::isString(obj0)) {
				this->predecessor = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Types");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->types.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->types[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CanLearn");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->canLearn.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->canLearn[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LearnsAtLevel");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					int i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->learnsAtLevel[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "FrontView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->frontView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->backView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error PersonClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->iD = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Creatures");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->creatures.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isInt(obj1)) {
							this->creatures[i] = cyborgbear::toInt(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Overhead");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->overhead.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->overhead[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "FrontView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->frontView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->backView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error TileClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TerrainFlags");
		{
			if (cyborgbear::isInt(obj0)) {
				this->terrainFlags = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->import = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LowerAnims");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->lowerAnims.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->lowerAnims[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "UpperAnims");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->upperAnims.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->upperAnims[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error Person::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->personClass.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Sprite::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AnimLayers");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->animLayers.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->animLayers[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								{
									cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj2);
									if (cyborgbear::isObj(finalObj)) {
										retval |= this->animLayers[i][ii].loadJsonObj(obj2);
									} else {
										if (cyborgbear::isNull(obj2)) {
											retval |= cyborgbear::Error_MissingField;
										} else {
											retval |= cyborgbear::Error_TypeMismatch;
										}
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteType");
		{
			if (cyborgbear::isInt(obj0)) {
				this->spriteType = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->personID = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Speed");
		{
			if (cyborgbear::isInt(obj0)) {
				this->speed = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		{
			if (cyborgbear::isString(obj0)) {
				this->name = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ScriptPath");
		{
			if (cyborgbear::isString(obj0)) {
				this->scriptPath = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Tile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->tileClass.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Occupant");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->occupant.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Zone::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Tiles");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->tiles.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->tiles[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								if (!cyborgbear::isNull(obj2)) {
									if (cyborgbear::isArray(obj2)) {
										cyborgbear::JsonArrayOut array2 = cyborgbear::toArray(obj2);
										unsigned int size = cyborgbear::arraySize(array2);
										this->tiles[i][ii].resize(size);
										for (unsigned int iii = 0; iii < size; iii++) {
											cyborgbear::JsonValOut obj3 = cyborgbear::arrayRead(array2, iii);
											{
												cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj3);
												if (cyborgbear::isObj(finalObj)) {
													retval |= this->tiles[i][ii][iii].loadJsonObj(obj3);
												} else {
													if (cyborgbear::isNull(obj3)) {
														retval |= cyborgbear::Error_MissingField;
													} else {
														retval |= cyborgbear::Error_TypeMismatch;
													}
												}
											}
										}
									} else {
										retval |= cyborgbear::Error_TypeMismatch;
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "InitScripts");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->initScripts.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->initScripts[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Location");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->location.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::JsonValOut CreatureType::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->special);
		cyborgbear::objSet(obj, "Special", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->strongAgainst.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->strongAgainst[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "StrongAgainst", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->weakAgainst.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->weakAgainst[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "WeakAgainst", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut StatusEffect::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->attackerEffect);
		cyborgbear::objSet(obj, "AttackerEffect", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->enemyEffect);
		cyborgbear::objSet(obj, "EnemyEffect", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Fraction::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->current);
		cyborgbear::objSet(obj, "Current", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->available);
		cyborgbear::objSet(obj, "Available", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ModelFile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->type);
		cyborgbear::objSet(obj, "Type", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Point::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->x);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Size::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Bounds::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->x);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SaveVariables::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, cyborgbear::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->vars[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Vars", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteSheetImage::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->srcBounds.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "SrcBounds", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteSheet::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->tilesWide);
		cyborgbear::objSet(obj, "TilesWide", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->tilesHigh);
		cyborgbear::objSet(obj, "TilesHigh", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->tileWidth);
		cyborgbear::objSet(obj, "TileWidth", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->tileHeight);
		cyborgbear::objSet(obj, "TileHeight", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->srcFile);
		cyborgbear::objSet(obj, "SrcFile", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< int, models::SpriteSheetImage >::iterator n = this->images.begin(); n != this->images.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->images[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->imageIdIterator);
		cyborgbear::objSet(obj, "ImageIdIterator", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->recycledImageIds.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->recycledImageIds[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "RecycledImageIds", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureMove::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->type);
		cyborgbear::objSet(obj, "Type", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->power);
		cyborgbear::objSet(obj, "Power", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->requiresRegarge);
		cyborgbear::objSet(obj, "RequiresRegarge", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->script);
		cyborgbear::objSet(obj, "Script", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->burn.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Burn", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->freeze.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Freeze", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->paralyze.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Paralyze", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->poison.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Poison", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->sleep.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Sleep", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureMoveInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->creatureMove);
		cyborgbear::objSet(obj, "CreatureMove", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->pP.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PP", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Creature::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->iD);
		cyborgbear::objSet(obj, "ID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->creatureClass);
		cyborgbear::objSet(obj, "CreatureClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->male);
		cyborgbear::objSet(obj, "Male", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->level);
		cyborgbear::objSet(obj, "Level", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->health.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Health", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->attack);
		cyborgbear::objSet(obj, "Attack", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->specAttack);
		cyborgbear::objSet(obj, "SpecAttack", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->defense);
		cyborgbear::objSet(obj, "Defense", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->specDefense);
		cyborgbear::objSet(obj, "SpecDefense", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->burned);
		cyborgbear::objSet(obj, "Burned", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->frozen);
		cyborgbear::objSet(obj, "Frozen", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->poisoned);
		cyborgbear::objSet(obj, "Poisoned", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->asleep);
		cyborgbear::objSet(obj, "Asleep", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->moves.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->moves[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Moves", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut User::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->personID);
		cyborgbear::objSet(obj, "PersonID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->world);
		cyborgbear::objSet(obj, "World", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->zone);
		cyborgbear::objSet(obj, "Zone", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->xAddress);
		cyborgbear::objSet(obj, "XAddress", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->yAddress);
		cyborgbear::objSet(obj, "YAddress", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->layer);
		cyborgbear::objSet(obj, "Layer", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->accessorID);
		cyborgbear::objSet(obj, "AccessorID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->location.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Location", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneHeader::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->size.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Size", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SaveFile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, cyborgbear::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->vars[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Vars", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->user.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "User", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Image::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->spriteSheet);
		cyborgbear::objSet(obj, "SpriteSheet", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->imgId);
		cyborgbear::objSet(obj, "ImgId", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->defaultSize.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "DefaultSize", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut World::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->zones.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->zones[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Zones", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut AnimationSlide::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->interval);
		cyborgbear::objSet(obj, "Interval", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->image.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Image", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Animation::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->images.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->images[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut AnimLayer::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->point.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Point", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->animation.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Animation", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->successor);
		cyborgbear::objSet(obj, "Successor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->predecessor);
		cyborgbear::objSet(obj, "Predecessor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->types.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->types[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Types", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->canLearn.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->canLearn[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "CanLearn", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< int, string >::iterator n = this->learnsAtLevel.begin(); n != this->learnsAtLevel.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->learnsAtLevel[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "LearnsAtLevel", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->frontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->backView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut PersonClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->iD);
		cyborgbear::objSet(obj, "ID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->creatures.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->creatures[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Creatures", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->overhead.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->overhead[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Overhead", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->frontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->backView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut TileClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->terrainFlags);
		cyborgbear::objSet(obj, "TerrainFlags", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->lowerAnims.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->lowerAnims[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "LowerAnims", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->upperAnims.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->upperAnims[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "UpperAnims", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Person::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->personClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PersonClass", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Sprite::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->animLayers.size(); i++) {
			cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->animLayers[i].size(); ii++) {
				cyborgbear::JsonValOut obj0 = this->animLayers[i][ii].buildJsonObj();
				cyborgbear::JsonValOut out0 = obj0;
				cyborgbear::arrayAdd(out1, out0);
				cyborgbear::decref(out0);
			}
			cyborgbear::arrayAdd(out2, out1);
			cyborgbear::decref(out1);
		}
		cyborgbear::objSet(obj, "AnimLayers", out2);
		cyborgbear::decref(out2);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->spriteType);
		cyborgbear::objSet(obj, "SpriteType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->personID);
		cyborgbear::objSet(obj, "PersonID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->speed);
		cyborgbear::objSet(obj, "Speed", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name);
		cyborgbear::objSet(obj, "Name", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->scriptPath);
		cyborgbear::objSet(obj, "ScriptPath", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Tile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->tileClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "TileClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->occupant.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Occupant", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Zone::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out3 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->tiles.size(); i++) {
			cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->tiles[i].size(); ii++) {
				cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
				for (cyborgbear::VectorIterator iii = 0; iii < this->tiles[i][ii].size(); iii++) {
					cyborgbear::JsonValOut obj0 = this->tiles[i][ii][iii].buildJsonObj();
					cyborgbear::JsonValOut out0 = obj0;
					cyborgbear::arrayAdd(out1, out0);
					cyborgbear::decref(out0);
				}
				cyborgbear::arrayAdd(out2, out1);
				cyborgbear::decref(out1);
			}
			cyborgbear::arrayAdd(out3, out2);
			cyborgbear::decref(out2);
		}
		cyborgbear::objSet(obj, "Tiles", out3);
		cyborgbear::decref(out3);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->initScripts.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->initScripts[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "InitScripts", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->location.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Location", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureType::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureType::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void StatusEffect::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string StatusEffect::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Fraction::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Fraction::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ModelFile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ModelFile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Point::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Point::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Size::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Size::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Bounds::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Bounds::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SaveVariables::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SaveVariables::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteSheetImage::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteSheetImage::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteSheet::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteSheet::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureMove::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureMove::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureMoveInstance::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureMoveInstance::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Creature::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Creature::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void User::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string User::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ZoneInstance::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ZoneInstance::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ZoneHeader::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ZoneHeader::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SaveFile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SaveFile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Image::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Image::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void World::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string World::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void AnimationSlide::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string AnimationSlide::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Animation::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Animation::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void AnimLayer::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string AnimLayer::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void PersonClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string PersonClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void TileClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string TileClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Person::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Person::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Sprite::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Sprite::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Tile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Tile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Zone::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Zone::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}
