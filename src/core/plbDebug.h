/* This file is part of the Palabos library.
 *
 * The Palabos softare is developed since 2011 by FlowKit-Numeca Group Sarl
 * (Switzerland) and the University of Geneva (Switzerland), which jointly
 * own the IP rights for most of the code base. Since October 2019, the
 * Palabos project is maintained by the University of Geneva and accepts
 * source code contributions from the community.
 *
 * Contact:
 * Jonas Latt
 * Computer Science Department
 * University of Geneva
 * 7 Route de Drize
 * 1227 Carouge, Switzerland
 * jonas.latt@unige.ch
 *
 * The most recent release of Palabos can be downloaded at
 * <https://palabos.unige.ch/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLB_DEBUG_H
#define PLB_DEBUG_H

#include <cassert>

#ifdef PLB_DEBUG

#define PLB_ASSERT(COND)        assert(COND);
#define PLB_PRECONDITION(COND)  assert(COND);
#define PLB_POSTCONDITION(COND) assert(COND);
#define PLB_STATECHECK(A, B)    assert((A) == (B));

#else

#define PLB_ASSERT(COND)
#define PLB_PRECONDITION(COND)
#define PLB_POSTCONDITION(COND)
#define PLB_STATECHECK(A, B)

#endif  // PLB_DEBUG

// #if defined(_MSC_VER)
//     #define DISABLE_WARNING_PUSH           __pragma(warning( push ))
//     #define DISABLE_WARNING_POP            __pragma(warning( pop ))
//     #define DISABLE_WARNING(warningNumber) __pragma(warning( disable : warningNumber ))
//
//     // TODO : find warning numbers for those 3 (add DISABLE_WARNING(4100))
//     #define DISABLE_WARNING_CAST_FUNCTION_TYPE
//     #define DISABLE_WARNING_INT_IN_BOOL
//     #define DISABLE_WARNING_DEPRECATED_COPY
//     // other warnings you want to deactivate...
//
// #elif defined(__GNUC__) || defined(__clang__)
//     #define DO_PRAGMA(X) _Pragma(#X)
//     #define DISABLE_WARNING_PUSH           DO_PRAGMA(GCC diagnostic push)
//     #define DISABLE_WARNING_POP            DO_PRAGMA(GCC diagnostic pop)
//     #define DISABLE_WARNING(warningName)   DO_PRAGMA(GCC diagnostic ignored #warningName)
//
//     #if defined(__clang__) // GNUC is defined for clang too
//         #define DISABLE_WARNING_CAST_FUNCTION_TYPE
//     #else
//         #define DISABLE_WARNING_CAST_FUNCTION_TYPE    DISABLE_WARNING(-Wcast-function-type)
//     #endif
//     #define DISABLE_WARNING_INT_IN_BOOL           DISABLE_WARNING(-Wint-in-bool-context)
//     #define DISABLE_WARNING_DEPRECATED_COPY       DISABLE_WARNING(-Wdeprecated-copy)
//
//    // other warnings you want to deactivate...
//
// #else
//     #define DISABLE_WARNING_PUSH
//     #define DISABLE_WARNING_POP
//
//     #define DISABLE_WARNING_CAST_FUNCTION_TYPE
//     #define DISABLE_WARNING_INT_IN_BOOL
//     #define DISABLE_WARNING_DEPRECATED_COPY
//     // other warnings you want to deactivate...
//
// #endif

namespace plb {

// Programmatically enable core dumps for POSIX systems.
// In a parallel program, this function must be called after plbInit.
void enableCoreDumps();

// Make stdout and stderr unbuffered for better debugging.
void unbufferOutputStdStreams();

}  // namespace plb

#endif  // PLB_DEBUG_H
