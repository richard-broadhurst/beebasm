/*************************************************************************************************/
/**
	objectcode.h


	Copyright (C) Rich Talbot-Watkins 2007 - 2012

	This file is part of BeebAsm.

	BeebAsm is free software: you can redistribute it and/or modify it under the terms of the GNU
	General Public License as published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	BeebAsm is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
	even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along with BeebAsm, as
	COPYING.txt.  If not, see <http://www.gnu.org/licenses/>.
*/
/*************************************************************************************************/

#ifndef OBJECTCODE_H_
#define OBJECTCODE_H_

#include <cassert>
#include <cstdlib>

class LineParser;

class ObjectCode
{
public:

	static void Create();
	static void Destroy();
	static inline ObjectCode& Instance() { assert( m_gInstance != NULL ); return *m_gInstance; }

	inline void SetPC( int i )		{ m_PC = i; }
	inline int GetPC() const		{ return m_PC; }

	void SetCPU( int i );
	inline int GetCPU() const		{ return m_CPU; }

	inline const unsigned char* GetAddr( int i ) const { return m_aMemory + i; }

	void InitialisePass();

	void PutByte( unsigned int byte );
	void Assemble1( unsigned int opcode, LineParser * lp );
	void Assemble2( unsigned int opcode, unsigned int val );
	void Assemble3( unsigned int opcode, unsigned int addr );
	void IncBin( const char* filename, LineParser * lp );

	void SetGuard( int i );
	void Clear( int start, int end, bool bAll = true );

	void SetMapping( int ascii, int mapped );
	int GetMapping( int ascii ) const;

	void CopyBlock( int start, int end, int dest );

public:

	enum FLAGS
	{
		USED  = (1 << 0),
		GUARD = (1 << 1),
		CHECK = (1 << 2),
		DONT_CHECK = (1 << 3)
	};


	ObjectCode();
	~ObjectCode();

	unsigned char				m_aMemory[ 0x10000 ];
	unsigned char				m_aFlags[ 0x10000 ];
	int							m_PC;
	int							m_CPU;

	unsigned char				m_aMapChar[ 96 ];

	static ObjectCode*			m_gInstance;
};



#endif // OBJECTCODE_H_
