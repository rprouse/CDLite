
#include "stdafx.h"
#include "Version.h"

CVersion::CVersion( WORD major, WORD minor, WORD increment, WORD build ) :
nMajor( major ), nMinor( minor ), nIncrement( increment ), nBuild( build ) { }

CVersion::CVersion( const CString& version )
{
    Convert( version );
}

CVersion::CVersion( const CVersion & rhs ) :
nMajor( rhs.nMajor ), nMinor( rhs.nMinor ), nIncrement( rhs.nIncrement ), nBuild( rhs.nBuild ) { }

CVersion::~CVersion() { }

int CVersion::Convert( const CString& version )
{
    int ret;
    nMajor = nMinor = nIncrement = nBuild = 0;

    if ( version.Find( ',' ) != -1 )
        ret = sscanf( version, "%hu,%hu,%hu,%hu", &nMajor, &nMinor, &nIncrement, &nBuild );
    else
        ret = sscanf( version, "%hu.%hu.%hu.%hu", &nMajor, &nMinor, &nIncrement, &nBuild );
    return ret;
}

CVersion::operator CString() const
{
    return StringValue();
}

CString CVersion::StringValue() const
{
    CString ret;
    ret.Format( "%hu.%hu.%hu", nMajor, nMinor, nIncrement );
    return ret;
}

CString CVersion::ShortStringValue() const
{
    CString ret;
    ret.Format( "%hu.%hu", nMajor, nMinor );
    return ret;
}

CVersion& CVersion::operator=( const CVersion& rhs )
{
    if ( this == &rhs )
        return *this;

    nMajor = rhs.nMajor;
    nMinor = rhs.nMinor;
    nIncrement = rhs.nIncrement;
    nBuild = rhs.nBuild;

    return *this;
}

CVersion& CVersion::operator=( const CString& rhs )
{
    Convert( rhs );
    return *this;
}

bool CVersion::operator>( const CVersion& rhs ) const
{
    if ( nMajor > rhs.nMajor )
        return true;
    if ( nMajor == rhs.nMajor && nMinor > rhs.nMinor )
        return true;
    if ( nMajor == rhs.nMajor && nMinor == rhs.nMinor && nIncrement > rhs.nIncrement )
        return true;
    if ( nMajor == rhs.nMajor && nMinor == rhs.nMinor && nIncrement == rhs.nIncrement && nBuild > rhs.nBuild )
        return true;
    return false;
}

WORD CVersion::Major( void ) const
{
    return nMajor;
}

WORD CVersion::Minor( void ) const
{
    return nMinor;
}

WORD CVersion::Increment( void ) const
{
    return nIncrement;
}

WORD CVersion::Build( void ) const
{
    return nBuild;
}

