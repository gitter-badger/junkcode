/**
 * @file singlemodel.cpp
 * @author Wei-Cheng Pan
 *
 * KomiX, a comics viewer.
 * Copyright (C) 2008  Wei-Cheng Pan <legnaleurc@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "conductor.hpp"
#include "singlemodel.hpp"

namespace {

bool check( const QUrl & url ) {
    if( url.scheme() == "file" ) {
        QFileInfo fi( url.toLocalFile() );
        if( !fi.isDir() ) {
            QString suffix = fi.suffix().toLower();
            foreach( QString ext, fbv::Conductor::SupportedFormats() ) {
                if( suffix == ext ) {
                    return true;
                }
            }
        }
    }
    return false;
}

std::shared_ptr< fbv::model::FileModel > create( const QUrl & url ) {
    return std::shared_ptr< fbv::model::FileModel >( new fbv::model::SingleModel( QFileInfo( url.toLocalFile() ) ) );
}

static const bool registered = fbv::model::FileModel::registerModel( check, create );

} // end of namespace

using namespace fbv::model;

SingleModel::SingleModel( const QFileInfo & root ) : LocalFileModel( root.dir() ) {
}
