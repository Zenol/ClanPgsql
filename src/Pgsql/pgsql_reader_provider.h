/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Jeremy Cochoy
*/

/// \addtogroup clanPgsql_System clanPgsql System
/// \{


#pragma once


#include <libpq-fe.h>
#include "ClanLib/Database/db_reader_provider.h"

namespace clan
{

class PgsqlCommandProvider;
class PgsqlConnectionProvider;

/// \brief Pgsql database reader provider.
class PgsqlReaderProvider : public DBReaderProvider
{
/// \name Construction
/// \{
public:
	PgsqlReaderProvider(PgsqlConnectionProvider *connection, PgsqlCommandProvider *command);
	~PgsqlReaderProvider();
/// \}

/// \name Attributes
/// \{
public:
	int get_column_count() const;
	std::string get_column_name(int index) const;
	int get_name_index(const std::string &name) const;
	std::string get_column_string(int index) const;
	bool get_column_bool(int index) const;
	char get_column_char(int index) const;
	unsigned char get_column_uchar(int index) const;
	int get_column_int(int index) const;
	unsigned int get_column_uint(int index) const;
	double get_column_double(int index) const;
	DateTime get_column_datetime(int index) const;
	DataBuffer get_column_binary(int index) const;
/// \}

/// \name Operations
/// \{
public:
	bool retrieve_row();
	void close();
/// \}

/// \name Implementation
/// \{
private:
	enum class ResultType
	{
		EMPTY_RESULT,
		TUPLES_RESULT
	};

	PgsqlConnectionProvider *connection;
	PgsqlCommandProvider *command;
	PGresult *result;
	ResultType type;
	bool closed;
	int current_row;
	int nb_rows;

	friend class PgsqlConnectionProvider;
	friend class PgsqlCommandProvider;
/// \}
};

};

/// \}
