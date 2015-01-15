// Contributed by Elie Morisse, same license DMD uses

#ifndef DMD_CPP_CPPMODULE_H
#define DMD_CPP_CPPMODULE_H

#ifdef __DMC__
#pragma once
#endif /* __DMC__ */

#include "root.h"
#include "dsymbol.h"
#include "module.h"
#include "cpp/calypso.h"

namespace clang
{
class Decl;
}

namespace cpp {

class Module : public ::Module
{
public:
    CALYPSO_LANGPLUGIN

    const clang::Decl *rootDecl = nullptr; // the decl we're generating the module for

    static Package *rootPackage;    // package to store all C++ packages/modules, avoids name clashes (e.g std)
    static Modules amodules;            // array of all modules
    static void init();

    Module(const char *filename, Identifier *ident, Identifiers *packages);

    static Module *load(Loc loc, Identifiers *packages, Identifier *ident);
};

}

#endif /* DMD_CPP_CPPMODULE_H */