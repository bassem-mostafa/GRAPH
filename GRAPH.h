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

/**
 *  @file
 *
 *  @brief Platform GRAPH Library
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Library
 *
 *  @{
 */

/**
 *  @defgroup Platform_GRAPH GRAPH
 *
 *  @{
 */

#ifndef GRAPH_H_
    #define GRAPH_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief GRAPH Operation Status
     *
     *  @enum GRAPH_Status_t
     */
    typedef enum GRAPH_Status
    {
        GRAPH_Status_Success = 0,     ///< Success
        GRAPH_Status_ArgumentInvalid, ///< Argument Invalid
        GRAPH_Status_NotSupported,    ///< Not Supported
        GRAPH_Status_Error,           ///< General Error
    } GRAPH_Status_t;

    /**
     * @brief Graph Node (Forward declaration)
     *
     * @struct GRAPH_Node_t
     */
    typedef struct GRAPH_Node GRAPH_Node_t;

    /**
     * @brief Graph Link (Forward declaration)
     *
     * @struct GRAPH_Link_t
     */
    typedef struct GRAPH_Link GRAPH_Link_t;

    /**
     * @brief Graph Node ( Vertex )
     *
     * @struct GRAPH_Node_t
     */
    typedef struct GRAPH_Node
    {
        /**
         *  @brief Next Node
         */
        GRAPH_Node_t * Next;

        /**
         *  @brief Previous Node
         */
        GRAPH_Node_t * Previous;

        /**
         *  @brief Head/start
         */
        GRAPH_Link_t * Head;

        /**
         *  @brief Tail/end
         */
        GRAPH_Link_t * Tail;
    } GRAPH_Node_t;

    /**
     * @brief Graph Link ( Edge )
     *
     * @struct GRAPH_Link_t
     */
    typedef struct GRAPH_Link
    {
        /**
         *  @brief Source Node
         */
        GRAPH_Node_t * Source;

        /**
         *  @brief Target Node
         */
        GRAPH_Node_t * Target;

        /**
         *  @brief Next Link
         */
        GRAPH_Link_t * Next;

        /**
         *  @brief Previous Link
         */
        GRAPH_Link_t * Previous;
    } GRAPH_Link_t;

    /**
     * @brief Graph
     *
     * @struct GRAPH_t
     */
    typedef struct GRAPHx
    {
        /**
         *  @brief Head/start
         */
        GRAPH_Node_t * Head;

        /**
         *  @brief Tail/end
         */
        GRAPH_Node_t * Tail;
    } GRAPH_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     * @brief Initialize graph instance
     *
     * @note MUST BE called before using any GRAPH API
     *
     * @param[out] GRAPHx Instance
     *
     * @return GRAPH_Status_t
     */
    GRAPH_Status_t GRAPH_Initialize( GRAPH_t * GRAPHx );

    /**
     * @brief Add a node into the graph
     *
     * @param[in] GRAPHx Instance
     * @param[in] Node   Node
     *
     * @return GRAPH_Status_t
     */
    GRAPH_Status_t GRAPH_AddNode( GRAPH_t * GRAPHx, GRAPH_Node_t * Node );

    /**
     * @brief Remove a node from the graph
     *
     * @param[in] GRAPHx Instance
     * @param[in] Node   Node
     *
     * @return GRAPH_Status_t
     */
    GRAPH_Status_t GRAPH_RemoveNode( GRAPH_t * GRAPHx, GRAPH_Node_t * Node );

    /**
     * @brief Add a link into the graph
     *
     * @param[in] GRAPHx Instance
     * @param[in] Link   Link
     *
     * @return GRAPH_Status_t
     */
    GRAPH_Status_t GRAPH_AddLink( GRAPH_t * GRAPHx, GRAPH_Link_t * Link );

    /**
     * @brief Remove a link from the graph
     *
     * @param[in] GRAPHx Instance
     * @param[in] Link   Link
     *
     * @return GRAPH_Status_t
     */
    GRAPH_Status_t GRAPH_RemoveLink( GRAPH_t * GRAPHx, GRAPH_Link_t * Link );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char GRAPH_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* GRAPH_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
