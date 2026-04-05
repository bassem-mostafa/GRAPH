// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include <stddef.h>

#include "GRAPH.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

GRAPH_Status_t GRAPH_Initialize( GRAPH_t * GRAPHx )
{
    GRAPH_Status_t Status = GRAPH_Status_Success;

    do
    {
        if ( GRAPHx == NULL )
        {
            Status = GRAPH_Status_ArgumentInvalid;
            break;
        }

        GRAPHx->Head = NULL;
        GRAPHx->Tail = NULL;
    }
    while ( 0 );

    return Status;
}

GRAPH_Status_t GRAPH_AddNode( GRAPH_t * GRAPHx, GRAPH_Node_t * Node )
{
    GRAPH_Status_t Status = GRAPH_Status_Success;

    do
    {
        if ( GRAPHx == NULL || Node == NULL )
        {
            Status = GRAPH_Status_ArgumentInvalid;
            break;
        }

        if ( ( GRAPHx->Head != GRAPHx->Tail ) && ( ( GRAPHx->Head == NULL ) || ( GRAPHx->Tail == NULL ) ) )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        if ( ( GRAPHx->Head == GRAPHx->Tail ) && ( GRAPHx->Tail == NULL ) )
        {
            GRAPHx->Head = Node;
            GRAPHx->Tail = Node;

            Node->Next = NULL;
            Node->Previous = NULL;
        }
        else
        {
            Node->Previous = GRAPHx->Tail;

            Node->Next = GRAPHx->Tail->Next;
            GRAPHx->Tail->Next = Node;

            GRAPHx->Tail = Node;
        }

        Node->Head = NULL;
        Node->Tail = NULL;
    }
    while ( 0 );

    return Status;
}

GRAPH_Status_t GRAPH_RemoveNode( GRAPH_t * GRAPHx, GRAPH_Node_t * Node )
{
    GRAPH_Status_t Status = GRAPH_Status_Success;

    do
    {
        if ( GRAPHx == NULL || Node == NULL )
        {
            Status = GRAPH_Status_ArgumentInvalid;
            break;
        }

        if ( ( GRAPHx->Head != GRAPHx->Tail ) && ( ( GRAPHx->Head == NULL ) || ( GRAPHx->Tail == NULL ) ) )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        if ( ( GRAPHx->Head == GRAPHx->Tail ) && ( GRAPHx->Head == NULL ) )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        GRAPH_Node_t * Target = GRAPHx->Head;
        while ( ( Target != NULL ) && ( Target != Node ) )
        {
            Target = Target->Next;
        }

        if ( Target == NULL )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        GRAPH_Node_t * Previous = Target->Previous;
        GRAPH_Node_t * Next = Target->Next;

        if ( Previous )
        {
            Previous->Next = Next;
        }

        if ( Next )
        {
            Next->Previous = Previous;
        }

        Target->Next = NULL;
        Target->Previous = NULL;

        // TODO Is there any actions for attached links ?
        // Target->Head = NULL;
        // Target->Tail = NULL;
    }
    while ( 0 );

    return Status;
}

GRAPH_Status_t GRAPH_AddLink( GRAPH_t * GRAPHx, GRAPH_Link_t * Link )
{
    GRAPH_Status_t Status = GRAPH_Status_Success;

    do
    {
        if ( GRAPHx == NULL || Link == NULL )
        {
            Status = GRAPH_Status_ArgumentInvalid;
            break;
        }

        if ( ( GRAPHx->Head != GRAPHx->Tail ) && ( ( GRAPHx->Head == NULL ) || ( GRAPHx->Tail == NULL ) ) )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        GRAPH_Node_t * Source = GRAPHx->Head;
        while ( ( Source != NULL ) && ( Source != Link->Source ) )
        {
            Source = Source->Next;
        }

        GRAPH_Node_t * Target = GRAPHx->Head;
        while ( ( Target != NULL ) && ( Target != Link->Target ) )
        {
            Target = Target->Next;
        }

        if ( Source == NULL || Target == NULL )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        if ( ( Source->Head != Source->Tail ) && ( ( Source->Head == NULL ) || ( Source->Tail == NULL ) ) )
        {
            Status = GRAPH_Status_Error;
            break;
        }

        if ( ( Source->Head == Source->Tail ) && ( Source->Tail == NULL ) )
        {
            Source->Head = Link;
            Source->Tail = Link;

            Link->Next = NULL;
            Link->Previous = NULL;
        }
        else
        {
            Link->Previous = Source->Tail;

            Link->Next = Source->Tail->Next;
            Source->Tail->Next = Link;

            Source->Tail = Link;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char GRAPH_VERSION[] = "0.0.0.v20260406-0117";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
