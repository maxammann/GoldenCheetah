/*
 * Copyright (c) 2016 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef GC_REMBED_H
#define GC_REMBED_H

// R and its data structures
#define R_NO_REMAP // don't map length(x) -> Rf_length for older code base
#include <R.h>
#include <Rinternals.h>

// get rid of #define TRUE/FALSE if QT4 has defined them
// since they clash with Rboolean enums
#ifdef TRUE
#undef TRUE
#endif
#ifdef FALSE
#undef FALSE
#endif

// specific to embedding
#include <Rembedded.h>
#include <R_ext/Parse.h>
#include <R_ext/Rdynload.h>
#include <R_ext/RStartup.h>

#include <QString>
#include <QStringList>

// a plain C++ class, no QObject stuff
class REmbed {

    public:
    
    REmbed(const int argc, const char* const argv[], const bool verbose=false, const bool interactive=false);
    ~REmbed();

    // modelled on equivalents for RInside to help transition
    int  parseEval(QString cmd, SEXP &ans);
    void parseEvalQ(QString cmd);
    void parseEvalQNT(QString cmd);
    SEXP parseEval(QString);
    SEXP parseEvalNT(QString);

    // the program being constructed/parsed
    QStringList program;

    bool verbose;
    bool interactive;

    bool loaded;
};

#endif
