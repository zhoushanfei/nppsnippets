/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  NppSnippets - Code Snippets plugin for Notepad++                       //
//  Copyright (C) 2013 Frank Fesevur                                       //
//                                                                         //
//  This program is free software; you can redistribute it and/or modify   //
//  it under the terms of the GNU General Public License as published by   //
//  the Free Software Foundation; either version 2 of the License, or      //
//  (at your option) any later version.                                    //
//                                                                         //
//  This program is distributed in the hope that it will be useful,        //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           //
//  GNU General Public License for more details.                           //
//                                                                         //
//  You should have received a copy of the GNU General Public License      //
//  along with this program; if not, write to the Free Software            //
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SqliteDB.h"

class SnippetsDB : public SqliteDatabase
{
public:
	SnippetsDB();
	SnippetsDB(LPCWSTR file);

	virtual void Open();
	void CreateExportDB();

	void ImportLibrary(LPCWSTR db, int orgLibID);

protected:
	void SetValues();
	void UpgradeDatabase_1_2();
	void UpgradeDatabase_2_3();
	bool CheckDBVersion();

	void ImportSnippets(int orgLibID, int newLibID);
	void ImportLanguages(int orgLibID, int newLibID);
};

extern SnippetsDB* g_db;
