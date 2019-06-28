// *********************************************************************************************************************
// API dll functions
//
// Module:			API
// Namespace:		-
// Contact person:
//
// [SG compatible]
// *********************************************************************************************************************

#if !defined (ACAPINC_DLL_H)
#define	ACAPINC_DLL_H

#if defined (_MSC_VER)
#pragma once
#endif


// --- Includes	--------------------------------------------------------------------------------------------------------

#if defined (WINDOWS)
#include "Win32Interface.hpp"
#endif

// GSRoot
#include "GSRoot.hpp"
#include "Array.hpp"
#include "PagedArray.hpp"
#include "UniString.hpp"

// own
#include "APICalls.h"
#include "APIdefs.h"
#include "APIdefs_Registration.h"
#include "API_Guid.hpp"

// --- Predeclarations -------------------------------------------------------------------------------------------

namespace Geometry {
	class PolyId;

	template <class VertexUserData, class EdgeUserData, class ContourUserData, class PolygonUserData> class CustomMultiPolygon2D;
	typedef CustomMultiPolygon2D<PolyId, PolyId, PolyId, PolyId> MultiPolygon2D;
}

// --- Compiler settings -----------------------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

#if defined (_MSC_VER)
	#pragma pack(push, 8)
#endif


// --- Predeclarations -------------------------------------------------------------------------------------------

namespace Modeler {
	class MeshBody;
}


// --- Function declarations -------------------------------------------------------------------------------------------

// =============================================================================
// Functions must be supported by the addon
//
// Following functions must be implemented in each extension.
// They are called from ARCHICAD.
// For detailed description refer to the enclosed documentation.
//
// =============================================================================

API_AddonType	__ACDLL_CALL	CheckEnvironment (API_EnvirParams* envirParams);
GSErrCode		__ACDLL_CALL	RegisterInterface (void);
GSErrCode		__ACDLL_CALL	Initialize (void);
GSErrCode		__ACDLL_CALL	FreeData (void);

typedef void*	ClientID;

#if defined (ACExtension)
/* [ --> */
// =============================================================================
// Function supported by the API
//
// Following functions are supported by the ACAP library.
// For detailed description refer to the enclosed documentation.
//
// =============================================================================

#include "APIdefs_Callback.h"


/* -- Server ------------------------------ */
#define	ServerMainVers_600			0x0001			// Package 6.00:  (ARCHICAD 6.0, PlotMaker 2.1)
#define	ServerMainVers_650			0x0002			// Package 6.50:  (ARCHICAD 6.5, PlotMaker 2.2)
#define	ServerMainVers_700			0x0003			// Package 7.00:  (ARCHICAD 7.0, PlotMaker 2.3)
#define	ServerMainVers_800			0x0004			// Package 8.00:  (ARCHICAD 8,   PlotMaker 3)
#define	ServerMainVers_810			0x0005			// Package 8.10:  (ARCHICAD 8.1, PlotMaker 3.1)
#define	ServerMainVers_900			0x0006			// Package 9.00:  (ARCHICAD 9,   PlotMaker 9)
#define	ServerMainVers_1000			0x000A			// ARCHICAD 10
#define	ServerMainVers_1100			0x000B			// ARCHICAD 11
#define	ServerMainVers_1200			0x000C			// ARCHICAD 12
#define	ServerMainVers_1300			0x000D			// ARCHICAD 13
#define	ServerMainVers_1400			0x000E			// ARCHICAD 14
#define	ServerMainVers_1500			0x000F			// ARCHICAD 15
#define	ServerMainVers_1600			0x0010			// ARCHICAD 16
#define	ServerMainVers_1700			0x0011			// ARCHICAD 17
#define	ServerMainVers_1800			0x0012			// ARCHICAD 18
#define	ServerMainVers_1900			0x0013			// ARCHICAD 19
#define	ServerMainVers_2000			0x0014			// ARCHICAD 20
#define	ServerMainVers_2100			0x0015			// ARCHICAD 21
#define	ServerMainVers_2200		    0x0016			// ARCHICAD 22

#define	ServerReleaseVers_R1		1



__APIEXPORT void		__ACENV_CALL	ACAPI_GetReleaseNumber (ClientID clientPtr, API_ServerApplicationInfo	*serverApplicationInfo);

/* -- System ------------------------------ */

#if defined (WINDOWS)
__APIEXPORT HINSTANCE	__ACENV_CALL	ACAPI_GetExtensionInstance (void);

__APIEXPORT HWND		__ACENV_CALL	ACAPI_GetMainWindow (ClientID clientPtr);
#endif
__APIEXPORT GSResModule	__ACENV_CALL	ACAPI_GetOwnResModule (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_GetOwnLocation (IO::Location *ownFileLoc);

__APIEXPORT void		__ACENV_CALL	ACAPI_SetDllTermHookProc (APIDllTermHookProc* dllTermHookProc);


/* -- Registration ------------------ */

	// CheckEnvironment
__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_SupportedService (GSType cmdID, Int32 cmdVersion);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_RequiredService (const API_ModulID	*modulID,
																		GSType				cmdID,
																		Int32				cmdVersion);

	// RegisterInterface
__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_Menu		(short			menuStrResID,
																 short			promptStrResID,
																 APIMenuCodeID	menuPosCode,
																 GSFlags		menuFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_FileType (Int32			refCon,
																 GSType			ftype,
																 GSType			fcreator,
																 const char		*extname,
																 short			iconResID,
																 short			descStrResID,
																 short			descStrResItemID,
																 API_IOMethod	methodFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_Subtype	(GSType				signature,				// identifier
																 short				templateFileResID,		// subtype template (FILE resource ID)
																 bool				transparentNode,		// allow ancestor tools to place object instances
																 short				stringResID,			// tool descriptions (STR# resource ID)
																 short				smallIconResID,			// toolbar icon
																 short				largeIconResID,			// toolbox icon
																 API_TBoxGroup		toolGroupId,			// toolbar group
																 API_TBoxEnabled	enableFlags,			// toolbar enable flags
																 short				defaultsResID);			// factory defaults (ACP0 resource ID)

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_SettingsPanel	(Int32					refCon,
																		 API_ElemTypeID			tool,
																		 API_ElemVariationID	variation,
																		 short					iconId,
																		 short					stringId,
																		 short					pageId,
																		 short					growType = 0,	// means NoGrow
																		 bool					visibleByDefault = false);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_AttributePanel	(Int32					refCon,
																		 API_AttrTypeID			attr,
																		 short					iconId,
																		 short					stringId,
																		 short					pageId,
																		 short					growType = 0);	// means NoGrow

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_InfoBoxPanel		(Int32					refCon,
																		 API_ElemTypeID			tool,
																		 API_ElemVariationID	variation,
																		 short					stringId,
																		 short					pageId,
																		 bool					visibleByDefault = false);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_ESYM		(GSType			signature,				// LibPart owner ID
																 API_LibTypeID	typeID,					// LibPart base type (Window, Door, Object, Lamp)
																 short			stringResID);			// description

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_PropertyObjectHandler (short assignStrResID);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_BuiltInLibrary (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_ModulDataHandler (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_ClassificationVisibilityHandler (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_PropertyVisibilityHandler (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_AddOnObjectHandler (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_NavigatorAddOnViewPointDataHandler (void);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Register_SettingsObserver (API_ElemTypeID			tool,
																		 API_ElemVariationID	variation);


	// Initialize
__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_ModulCommandHandler  (ClientID				clientPtr,
																			GSType					cmdID,
																			Int32					cmdVersion,
																			APIModulCommandProc*	handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_MenuHandler		   (ClientID				clientPtr,
																			short					menuStrResID,
																			APIMenuCommandProc*		handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_FileTypeHandler	   (ClientID				clientPtr,
																			GSType					cmdID,
																			APIIOCommandProc*		handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_FileTypeHandler3D	   (ClientID				clientPtr,
																			GSType					cmdID,
																			APIIO3DCommandProc*		handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_PanelHandler (ClientID				clientPtr,
																	Int32					refCon,
																	APIPanelCreateProc*		handlerCreateProc,
																	APIPanelDestroyProc*	handlerDestroyProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_ESYMHandler		   (ClientID				clientPtr,
																			GSType					signature,
																			APIESYMCommandProc*		handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_PropertyObjectHandler	(ClientID						clientPtr,
																			 short							strResID,
																			 APIPropertyObjectCommandProc* 	propertyCommandProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_ModulDataMergeHandler	(ClientID						clientPtr,
																			 APIModulDataMergeHandlerProc*	mergeHandlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_ModulDataSaveOldFormatHandler (ClientID								clientPtr,
																					 APIModulDataSaveOldFormatHandlerProc*	modulDataSaveOldFormatProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_ElemSetSaveOldFormatHandler (ClientID								clientPtr,
																				   APIElemSetSaveOldFormatHandlerProc*	elemSetSaveOldFormatProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_AddOnObjectMergeHandler			(ClientID										clientPtr,
																						 APIAddonObjectMergeHandlerProc*				mergeHandlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_AddOnObjectSaveOldFormatHandler	(ClientID										clientPtr,
																						 APIAddonObjectSaveOldFormatHandlerProc*		saveOldFormatProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_AddOnObjectConvertNewFormatHandler (ClientID										clientPtr,
																						  APIAddonObjectConvertNewFormatHandlerProc*	convertNewFormatProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_NavigatorAddOnViewPointDataMergeHandler			 (ClientID														clientPtr,
																										  APINavigatorAddOnViewPointDataMergeHandlerProc*				mergeHandlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_NavigatorAddOnViewPointDataSaveOldFormatHandler	 (ClientID														clientPtr,
																										  APINavigatorAddOnViewPointDataSaveOldFormatHandlerProc*		saveOldFormatProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_NavigatorAddOnViewPointDataConvertNewFormatHandler (ClientID														clientPtr,
																										  APINavigatorAddOnViewPointDataConvertNewFormatHandlerProc*	convertNewFormatProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_SettingsHandler (ClientID						clientPtr,
																	   API_ElemTypeID				tool,
																	   API_ElemVariationID			variation,
																	   APISettingsCreateProc*		handlerCreateProc,
																	   APISettingsDestroyProc*		handlerDestroyProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_ClassificationVisibilityHandler (ClientID										clientPtr,
																					   APIClassificationVisibilityHandlerProc*		handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Install_PropertyVisibilityHandler (ClientID							clientPtr,
																				APIPropertyVisibilityHandlerProc*	handlerProc);

/* -- Memory Manager ---------------------- */
/**
 * @defgroup MemMgr Memory Manager
 */
/*@{*/

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeAddParHdl (API_AddParType ***addPars);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeParagraphsHdl (API_ParagraphType ***paragraphs);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeElemMemoHdls (API_ElementMemo *memo);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeAttrDefsHdls (API_AttributeDef *defs);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeAttrDefsHdlsExt (API_AttributeDefExt *defs);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeRoomRelationHdls (API_RoomRelation *roomInfo);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeWallRelationHdls (API_WallRelation *wallInfo);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeBeamRelationHdls (API_BeamRelation *beamInfo);

__APIEXPORT void		__ACENV_CALL	ACAPI_DisposeWorkspaceInfoHdls (API_WorkspaceInfo *workspaceInfo);

__APIEXPORT void		__ACENV_CALL	ACAPI_FreeGridMeshPtr (API_GridMesh **gridMeshes);

__APIEXPORT void		__ACENV_CALL	ACAPI_FreeCWContourPtr (API_CWContourData **contours);

__APIEXPORT void		__ACENV_CALL	ACAPI_FreeGDLModelViewOptionsPtr (API_GDLModelViewOptions **gdlModelViewOptions);

/*@}*/

/* -- Resource Manager -------------------- */
/**
 * @defgroup ResMgr Resource Manager
 */
/*@{*/

__APIEXPORT bool		__ACENV_CALL	ACAPI_Resource_GetLocStr (char *str, short resID, short index, GSResModule resModule = ACAPI_GetOwnResModule ());

__APIEXPORT bool		__ACENV_CALL	ACAPI_Resource_GetLocUStr (GS::uchar_t *str, short resID, short index, GSResModule resModule = ACAPI_GetOwnResModule ());

__APIEXPORT bool		__ACENV_CALL	ACAPI_Resource_GetFixStr (char *str, short resID, short index, GSResModule resModule = ACAPI_GetOwnResModule ());

/*@}*/

/* -- Client Manager ---------------------- */
__APIEXPORT void		__ACENV_CALL	ACAPI_KeepInMemory (ClientID clientPtr, bool keepIn);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_SetPreferences (ClientID clientPtr, Int32 version, GSSize nByte, const void *data);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_GetPreferences (ClientID clientPtr, Int32 *version, GSSize *nByte, void *data);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_GetPreferences_Platform (ClientID			clientPtr,
																	   Int32			*version,
																	   GSSize			*nByte,
																	   void				*data,
																	   unsigned short	*platformSign);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_SetPreferences_OldVersion (ClientID			clientPtr,
																		 Int32				version,
																		 GSSize				nByte,
																		 const void*		data,
																		 unsigned short		platformSign,
																		 API_FTypeID		oldPlanFileID);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_RegisterModelessWindow (ClientID						clientPtr,
																	  Int32							referenceID,
																	  APIPaletteControlCallBackProc	*callBackProc,
																	  GSFlags						controlFlags,
																	  const API_Guid&				paletteGuid = APINULLGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_UnregisterModelessWindow (ClientID clientPtr, Int32 referenceID);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_CallUndoableCommand (ClientID clientPtr, const GS::UniString& undoString, const std::function<GSErrCode ()>& command);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_CallCommand (ClientID clientPtr, const GS::UniString& commandName, const std::function<GSErrCode ()>& command);

__APIEXPORT void		__ACENV_CALL	ACAPI_WriteReport (ClientID clientPtr, const GS::UniString& format, bool withDial, ...);

/* -- General Manager --------------------- */
/**
 * @defgroup GenFunc General Functions
 */
/*@{*/

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Database		(ClientID clientPtr, API_DatabaseID code, void* par1 = nullptr, void* par2 = nullptr, void* par3 = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Environment	(ClientID clientPtr, API_EnvironmentID code, void* par1 = nullptr, void* par2 = nullptr, void* par3 = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Interface		(ClientID clientPtr, API_InterfaceID code, void* par1 = nullptr, void* par2 = nullptr, void* par3 = nullptr, void* par4 = nullptr, void* par5 = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Goodies		(ClientID clientPtr, API_GoodiesID code, void* par1 = nullptr, void* par2 = nullptr, void* par3 = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Automate		(ClientID clientPtr, API_AutomateID code, void* par1 = nullptr, void* par2 = nullptr, void* par3 = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Navigator		(ClientID clientPtr, API_NavigatorID code, void* par1 = nullptr, void* par2 = nullptr, void* par3 = nullptr);

/*@}*/

/* -- Override Manager --------------------- */
/**
 * @defgroup OverMan Override manager
 */
/*@{*/

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_GetOverrideCombinationList (ClientID clientPtr, GS::Array<API_Guid>& combinationList);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_GetOverrideRuleList		  (ClientID clientPtr, GS::Array<API_Guid>& ruleList);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_GetOverrideCombination	  (ClientID clientPtr, API_OverrideCombination& combination,
																				   GS::Array<API_Guid>* ruleList = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_GetOverrideRule			  (ClientID clientPtr, API_OverrideRule& rule);


__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_CreateOverrideCombination  (ClientID clientPtr, API_OverrideCombination& combination,
																				   const GS::Array<API_Guid>& ruleList);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_CreateOverrideRule		  (ClientID clientPtr, API_OverrideRule& rule);


__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_ChangeOverrideCombination  (ClientID clientPtr, const API_OverrideCombination& combination,
																				   const GS::Array<API_Guid>* const ruleList = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_ChangeOverrideRule		  (ClientID clientPtr, const API_OverrideRule& rule);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_DeleteOverrideCombination  (ClientID clientPtr, const API_Guid& combination);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Override_DeleteOverrideRule		  (ClientID clientPtr, const API_Guid& rule);

/*@}*/

/* -- Attribute Manager ------------------- */

/**
 * @defgroup AttrMan Attribute Manager
 */
/*@{*/

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_GetNum (ClientID clientPtr, API_AttrTypeID typeID, short *count);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_Get (ClientID clientPtr, API_Attribute *attribute);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_GetDef (ClientID clientPtr, API_AttrTypeID typeID, short index, API_AttributeDef *defs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_GetDefExt (ClientID				clientPtr,
																   API_AttrTypeID		typeID,
																   short				index,
																   API_AttributeDefExt	*defs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_Create (ClientID clientPtr, API_Attribute *attribute, API_AttributeDef *defs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_CreateExt (ClientID clientPtr, API_Attribute *attribute, API_AttributeDefExt *defs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_Modify (ClientID clientPtr, API_Attribute *attribute, API_AttributeDef *defs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_ModifyExt (ClientID clientPtr, API_Attribute *attribute, API_AttributeDefExt *defs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_Search (ClientID clientPtr, API_Attr_Head *attrHead);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_Delete (ClientID clientPtr, const API_Attr_Head *attrHead);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_DeleteMore (ClientID clientPtr, const API_Attr_Head *attrHead, short* attrIndexListPtr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_GetUserData (ClientID				clientPtr,
																	 API_Attr_Head			*attrHead,
																	 API_AttributeUserData	*userData);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Attribute_SetUserData (ClientID						clientPtr,
																	 API_Attr_Head					*attrHead,
																	 const API_AttributeUserData	*userData);

/*@}*/

/* -- Library Part Manager ---------------- */

/**
 * \defgroup LPMan Library Part Manager
 */
/*@{*/

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetNum (ClientID clientPtr, Int32 *count);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_Search (ClientID clientPtr, API_LibPart *ancestor, bool createIfMissing, bool onlyPlaceable = false);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_PatternSearch (ClientID clientPtr, const API_LibPart *ancestor, const GS::UniString& pattern, API_LibPart result[50], Int32* numFound);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_Get (ClientID clientPtr, API_LibPart *libPart);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetParams (ClientID		clientPtr,
																 Int32			libInd,
																 double			*a,
																 double			*b,
																 Int32			*addParNum,
																 API_AddParType	***addPars);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetSection (ClientID				clientPtr,
																  Int32					libInd,
																  API_LibPartSection	*section,
																  GSHandle				*sectionHdl,
																  GS::UniString			*sectionStr,
																  GS::UniString			*password = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_UpdateSection (ClientID					clientPtr,
																	 Int32						libInd,
																	 const API_LibPartSection	*section,
																	 GSHandle					sectionHdl,
																	 GS::UniString				*sectionStr,
																	 GS::UniString				*password = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_SetUpSect_2DDrawHdl (ClientID clientPtr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetSect_2DDrawHdl (ClientID clientPtr, GSHandle *sectionHdl);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetSect_ParamDef (ClientID			clientPtr,
																		const API_LibPart	*libPart,
																		API_AddParType		**addPars,
																		double				*a,
																		double				*b,
																		GSHandle			sect2DDrawHdl,
																		GSHandle			*sectionHdl,
																		GS::UniString		*password = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_Create (ClientID clientPtr, const API_LibPart *libPart);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_AddSection (ClientID					clientPtr,
																  const API_LibPartSection	*section,
																  GSHandle					sectionHdl,
																  GS::UniString				*sectionStr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_NewSection (ClientID clientPtr, const API_LibPartSection *section);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_WriteSection (ClientID clientPtr, Int32 nByte, GSConstPtr data);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_EndSection (ClientID clientPtr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_Save (ClientID clientPtr, API_LibPart *libPart);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_ShapePrims (ClientID			clientPtr,
																  Int32				libInd,
																  const API_Guid&	instanceElemGuid,
																  short				gdlContext,
																  ShapePrimsProc	*shapePrimsProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetHotspots (ClientID				clientPtr,
																   Int32				libInd,
																   const API_Guid&		instanceElemGuid,
																   Int32*				nHotspots,
																   API_PrimHotspot***	hotspots);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_Register (ClientID clientPtr, API_LibPart *libPart);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_RegisterAll (ClientID clientPtr, GS::Array<API_LibPart>* libParts);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetSectionList (ClientID				clientPtr,
																	  Int32					libInd,
																	  Int32					*nSection,
																	  API_LibPartSection	***sections);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_GetDetails (ClientID				clientPtr,
																  Int32					libInd,
																  API_LibPartDetails	*details);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_LibPart_SetDetails_ParamDef (ClientID				clientPtr,
																		   const API_LibPart		*libPart,
																		   GSHandle					paramHdl,
																		   const API_LibPartDetails	*details);

/*@}*/

/* -- Element Manager --------------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetDefaults (ClientID clientPtr, API_Element *element, API_ElementMemo *memo);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetDefaultsExt (ClientID				clientPtr,
																	  API_Element			*element,
																	  API_ElementMemo		*memo,
																	  UInt32				nSubElems,
																	  API_SubElemMemoMask	*subElems);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ChangeDefaults (ClientID			clientPtr,
																	  API_Element		*element,
																	  API_ElementMemo	*memo,
																	  const API_Element	*mask);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ChangeDefaultsExt (ClientID				clientPtr,
																		 API_Element			*element,
																		 API_ElementMemo		*memo,
																		 const API_Element		*mask,
																		 UInt32					nSubElems,
																		 API_SubElemMemoMask	*subElems);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetElemList (ClientID				clientPtr,
																   API_ElemTypeID		typeID,
																   GS::Array<API_Guid>*	elemList,
																   API_ElemFilterFlags	filterBits = APIFilt_None,
																   API_ElemVariationID	variationID = APIVarId_Generic,
																   const API_Guid&		renovationFilterGuid = APINULLGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetConnectedElements (ClientID				clientPtr,
																			const API_Guid&			guid,
																			API_ElemTypeID			connectedElemTypeID,
																			GS::Array<API_Guid>*	connectedElements,
																			API_ElemFilterFlags		filterBits = APIFilt_None,
																			API_ElemVariationID		variationID = APIVarId_Generic,
																			const API_Guid&		renovationFilterGuid = APINULLGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_Filter (ClientID				clientPtr,
															  const API_Guid&		guid,
															  API_ElemFilterFlags	filterBits,
															  API_ElemVariationID	variationID = APIVarId_Generic,
															  const API_Guid&		renovationFilterGuid = APINULLGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Get (ClientID		clientPtr,
														   API_Element	*element,
														   UInt32		mask = 0);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetHeader (ClientID		clientPtr,
														  		 API_Elem_Head	*elementHead,
																 UInt32			mask = 0);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetMemo	(ClientID					clientPtr,
																 const API_Guid&			guid,
																 API_ElementMemo*			memo,
																 UInt64						mask = APIMemoMask_All);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ChangeMemo (ClientID				clientPtr,
																  API_Guid&				guid,
																  UInt64				mask,
											   					  const API_ElementMemo	*memo);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetRelations (ClientID			clientPtr,
																	const API_Guid&		guid,
																	API_ElemTypeID		otherID,
																	void*				relData,
																	UInt32				mask = 0);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetSyTran (ClientID clientPtr, const API_Elem_Head *elemHead, API_SyTran *syTran);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetHotspots (ClientID							clientPtr,
																   const API_Guid&					guid,
																   GS::Array<API_ElementHotspot>*	hotspotArray);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Create (ClientID clientPtr, API_Element *element, API_ElementMemo *memo);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_CreateExt (ClientID				clientPtr,
																 API_Element			*element,
																 API_ElementMemo		*memo,
																 UInt32					nSubElems,
																 API_SubElemMemoMask	*subElems);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ChangeParameters (ClientID				clientPtr,
																		API_Elem_Head			**elemHead,
																		Int32					nItem,
							   											const API_Element		*defPars,
																		const API_ElementMemo	*defMemo,
												   						const API_Element		*mask);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Change (ClientID				clientPtr,
															  API_Element			*element,
															  const API_Element		*mask,
															  const API_ElementMemo	*memo,
															  UInt64				memoMask,
															  bool					withdel);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ChangeMore (ClientID				clientPtr,
																  API_Elem_Head			*elemHead,
																  Int32					nItem,
							   									  const API_Element		*defPars,
																  const API_ElementMemo	*defMemo,
												   				  const API_Element		*mask,
																  UInt64				memoMask,
																  bool					withdel);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ChangeExt (ClientID				clientPtr,
															  	 API_Element			*element,
																 const API_Element		*mask,
																 API_ElementMemo		*memo,
																 UInt64					memoMask,
																 UInt32					nSubElems,
																 API_SubElemMemoMask	*subElems,
																 bool					withdel,
																 Int32					subIndex);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Delete (ClientID clientPtr, API_Elem_Head **elemHead, Int32 nItem);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Edit (ClientID clientPtr, API_Neig **items, Int32 nItem, const API_EditPars *pars);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Tool (ClientID		clientPtr,
															API_Elem_Head	**elemHead,
															Int32			nItem,
															API_ToolCmdID	typeID,
															void			*pars);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Select (ClientID clientPtr, API_Neig **selNeig, Int32 nItem, bool add);


__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetUserData	(ClientID					clientPtr,
																	 API_Elem_Head				*elemHead,
																	 API_ElementUserData		*userData,
																	 UInt32						mask = 0);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetUserData	(ClientID					clientPtr,
																	 API_Elem_Head				*elemHead,
																	 const API_ElementUserData	*userData);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_DeleteUserData (ClientID clientPtr, API_Elem_Head *elemHead);

__APIEXPORT API_Guid	__ACENV_CALL	ACAPI_Element_UnIdToGuid (ClientID clientPtr, API_DatabaseUnId databaseUnId, UInt32 elemUnId);

__APIEXPORT UInt32		__ACENV_CALL	ACAPI_Element_GuidToUnId (ClientID clientPtr, API_Guid elemGuid, API_DatabaseUnId* databaseUnId);

__APIEXPORT API_Guid	__ACENV_CALL	ACAPI_Element_LinkIdToDrwGuid (ClientID clientPtr, Int32 linkId);

__APIEXPORT Int32		__ACENV_CALL	ACAPI_Element_DrwGuidToLinkId (ClientID clientPtr, API_Guid drwGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Link (ClientID	clientPtr,
															API_Guid	guid_linkFrom,
															API_Guid	guid_linkTo,
															GSFlags		linkFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Unlink (ClientID clientPtr, API_Guid guid_linkFrom, API_Guid guid_linkTo);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetLinks (ClientID	clientPtr,
																API_Guid	guid_linkFrom,
																API_Guid	***guid_linkTo,
																Int32 		*nLinks);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetLinkFlags (ClientID	clientPtr,
																	API_Guid	guid_linkFrom,
																	API_Guid	guid_linkTo,
																	GSFlags		*linkFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_AttachObserver (ClientID clientPtr, API_Elem_Head *elemHead, GSFlags notifyFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_DetachObserver (ClientID clientPtr, API_Elem_Head *elemHead);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetObservedElements (ClientID clientPtr, API_Elem_Head ***elemHead, Int32 *nElems);


__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidOperation_Create (ClientID				clientPtr,
																			 API_Guid				guid_Target,
																			 API_Guid				guid_Operator,
																			 API_SolidOperationID	operation,
																			 GS::Array<API_Guid>*	guid_Results = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_Create (ClientID				clientPtr,
																		API_Guid				guid_Target,
																		API_Guid				guid_Operator,
																		API_SolidOperationID	operation,
																		GSFlags					linkFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_Remove (ClientID	clientPtr,
																		API_Guid	guid_Target,
																		API_Guid	guid_Operator);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_GetTime (ClientID		clientPtr,
																		 API_Guid		guid_Target,
																		 API_Guid		guid_Operator,
																		 GSTime			*linkTime,
																		 UInt32			*linkSubTime);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_GetOperation (ClientID				clientPtr,
																			  API_Guid				guid_Target,
																			  API_Guid				guid_Operator,
																			  API_SolidOperationID	*operation);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_GetFlags (ClientID	clientPtr,
																		  API_Guid	guid_Target,
																		  API_Guid	guid_Operator,
																		  GSFlags	*linkFlags);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_GetTargets (ClientID	clientPtr,
																			API_Guid	guid_Operator,
																			API_Guid	***guid_Targets,
																			Int32		*nLinks);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SolidLink_GetOperators (ClientID	clientPtr,
																			  API_Guid	guid_Target,
																			  API_Guid	***guid_Operators,
																			  Int32		*nLinks);


__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Get3DInfo			(ClientID					clientPtr,
																		 const API_Elem_Head&		elemHead,
																		 API_ElemInfo3D				*info3D);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetVisualOverriddenImage (ClientID					clientPtr,
                                                                        		const API_Guid&				elemGuid,
																				API_VisualOverriddenImage	*image);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetQuantities		(ClientID							clientPtr,
																		 API_Guid							elemGuid,
								  										 const API_QuantityPar				*params,
																		 API_Quantities						*quantities,
																		 const API_QuantitiesMask			*mask = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetMoreQuantities	(ClientID							clientPtr,
																		 const GS::Array<API_Guid>			*elemGuids,
								  										 const API_QuantityPar				*params,
																		 GS::Array<API_Quantities>			*quantities,
																		 const API_QuantitiesMask			*mask = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetSurfaceQuantities	(ClientID								clientPtr,
																			 const GS::Array<API_Guid>				*elemGuids,
								  											 const GS::Array<API_Guid>				*coverElemGuids,
																			 GS::Array<API_ElemPartSurfaceQuantity>	*quantities);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyObjects	(ClientID					clientPtr,
																			 const API_Elem_Head*		elemHead,
																			 API_PropertyObjectRefType		***propRefs,
																			 Int32						*nProp);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetComponents		(ClientID					clientPtr,
																		 const API_Elem_Head*		elemHead,
																		 API_ComponentRefType		***compRefs,
																		 Int32						*nComp);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetDescriptors	(ClientID					clientPtr,
																		 const API_Elem_Head*		elemHead,
																		 API_DescriptorRefType		***descRef,
																		 Int32						*nDesc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ShapePrims		(ClientID				clientPtr,
																		 const API_Elem_Head&	elemHead,
																		 ShapePrimsProc			*shapePrimsProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_ShapePrimsExt (ClientID				clientPtr,
																	 const API_Elem_Head&	elemHead,
																	 ShapePrimsProc			*shapePrimsProc,
																	 API_ShapePrimsParams*	shapePrimsParams);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetLinkedPropertyObjects (ClientID				clientPtr,
																				const API_Elem_Head		*head,
																				bool					*criteria,
																				Int32					*inviduallyLibInd,
																				Int32					**critLibInds,
																				Int32					*nCrits);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetLinkedPropertyObjects (ClientID				clientPtr,
																				API_Elem_Head			*head,
																				bool					criteria,
																				Int32					inviduallyLibInd);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetCategoryValue (ClientID					clientPtr,
																		const API_Guid&				elemGuid,
																		const API_ElemCategory&		elemCategory,
																		API_ElemCategoryValue*		elemCategoryValue);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetCategoryValueDefault (ClientID						clientPtr,
																			   const API_ElemTypeID&		typeID,
																			   const API_ElemVariationID&	variationID,
																			   const API_ElemCategory&		elemCategory,
																			   API_ElemCategoryValue*		elemCategoryValue);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetCategoryValue (ClientID						clientPtr,
																		const API_Guid&					elemGuid,
																		const API_ElemCategory&			elemCategory,
																		const API_ElemCategoryValue&	elemCategoryValue);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetCategoryValueDefault (ClientID							clientPtr,
																			   const API_ElemTypeID&			typeID,
																			   const API_ElemVariationID&		variationID,
																			   const API_ElemCategory&			elemCategory,
																			   const API_ElemCategoryValue&		elemCategoryValue);

/* -- Element Composition ----------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Trim_Elements			(ClientID					clientPtr,
																			 const GS::Array<API_Guid>&	guid_ElementsToTrim);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Trim_ElementsWith		(ClientID					clientPtr,
																			 const GS::Array<API_Guid>&	guid_ElementsToTrim,
																			 const API_Guid&			guid_Element,
																			 API_TrimTypeID				trimType);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Trim_Remove			(ClientID					clientPtr,
																			 const API_Guid&			guid_Element1,
																			 const API_Guid&			guid_Element2);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Trim_GetTrimType		(ClientID					clientPtr,
																			 const API_Guid&			guid_Element1,
																			 const API_Guid&			guid_Element2,
																			 API_TrimTypeID*			trimType);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Trim_GetTrimmedElements	(ClientID				clientPtr,
																				 const API_Guid&		guid_Element,
																				 GS::Array<API_Guid>*	guid_TrimmedElements);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Trim_GetTrimmingElements	(ClientID				clientPtr,
																				 const API_Guid&		guid_Element,
																				 GS::Array<API_Guid>*	guid_TrimmingElements);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Merge_Elements			(ClientID					clientPtr,
																				 const GS::Array<API_Guid>&	guid_ElementsToMerge);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Merge_GetMergedElements	(ClientID				clientPtr,
																				 const API_Guid&		guid_Element,
																				 GS::Array<API_Guid>*	guid_MergedElements);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Merge_Remove				(ClientID			clientPtr,
																				 const API_Guid&	guid_Element1,
																				 const API_Guid&	guid_Element2);

/* -- IFC --------------------------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetIFCIdentifier		(ClientID						clientPtr,
																			 const API_Guid&				elementID,
																			 API_Guid&						archicadIFCID,
																			 API_Guid&						externalIFCID);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetElemListByIFCIdentifier	(ClientID						clientPtr,
																					 const API_Guid*				archicadIFCID,
																					 const API_Guid*				externalIFCID,
																					 GS::Array<API_Guid>&			elements);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetIFCType			(ClientID						clientPtr,
																			const API_Guid&					elementID,
																			GS::UniString*					ifcType,
																			GS::UniString*					typeObjectIFCType);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetIFCProperties		(ClientID						clientPtr,
																			 const API_Guid&				guid_Element,
																			 bool							storedOnly,
																			 GS::Array<API_IFCProperty>*	properties);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetIFCProperty		(ClientID						clientPtr,
																			 const API_Guid&				guid_Element,
																			 const API_IFCProperty&			property);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_RemoveIFCProperty		(ClientID						clientPtr,
																			 const API_Guid&				guid_Element,
																			 const API_IFCProperty&			property);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetIFCAttributes		(ClientID						clientPtr,
																			 const API_Guid&				guid_Element,
																			 bool							storedOnly,
																			 GS::Array<API_IFCAttribute>*	attributes);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetIFCAttribute		(ClientID						clientPtr,
																			 const API_Guid&				guid_Element,
																			 const API_IFCAttribute&		attribute);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetIFCClassificationReferences	(ClientID									clientPtr,
																						 const API_Guid&							guid_Element,
																						 bool										storedOnly,
																						 GS::Array<API_IFCClassificationReference>*	classificationReferences);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetIFCClassificationReference		(ClientID								clientPtr,
																						 const API_Guid&						guid_Element,
																						 const API_IFCClassificationReference&	classificationReference);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_RemoveIFCClassificationReference	(ClientID								clientPtr,
																						 const API_Guid&						guid_Element,
																						 const API_IFCClassificationReference&	classificationReference);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetIFCPropertyValuePrimitiveType	(ClientID								clientPtr,
																						 const GS::UniString&					valueType,
																						 API_IFCPropertyValuePrimitiveType*		primitiveType);

/* -- Classification related functions ----------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetClassificationItems	(ClientID clientPtr, const API_Guid& elemGuid, GS::Array<GS::Pair<API_Guid, API_Guid>>& systemItemPairs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetClassificationItemsDefault		(ClientID									clientPtr,
																						 API_ElemTypeID								typeID,
																						 API_ElemVariationID						variationID,
																						 GS::Array<GS::Pair<API_Guid, API_Guid>>&	systemItemPairs);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetClassificationInSystem (ClientID clientPtr, const API_Guid& elemGuid, const API_Guid& systemGuid, API_ClassificationItem& item);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetClassificationInSystemDefault	(ClientID					clientPtr,
																						 API_ElemTypeID				typeID,
																						 API_ElemVariationID		variationID,
																						 const API_Guid&			systemGuid,
																						 API_ClassificationItem&	item);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_AddClassificationItem		(ClientID clientPtr, const API_Guid& elemGuid, const API_Guid& itemGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_AddClassificationItemDefault	  (ClientID clientPtr, API_ElemTypeID typeID, API_ElemVariationID variationID, const API_Guid& itemGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_RemoveClassificationItem	(ClientID clientPtr, const API_Guid& elemGuid, const API_Guid& itemGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_RemoveClassificationItemDefault (ClientID clientPtr, API_ElemTypeID typeID, API_ElemVariationID variationID, const API_Guid& itemGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsClassificationItemVisible	(ClientID								clientPtr,
																					 const API_Guid&						elemGuid,
																					 const API_Guid&						classificationGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsClassificationItemVisibleDefault   (ClientID						clientPtr,
																							API_ElemTypeID					typeID,
																							API_ElemVariationID				variationID,
																							const API_Guid&					classificationGuid);



/* -- Property related functions ----------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyDefinitions				(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 API_PropertyDefinitionFilter			filter,
																							 GS::Array<API_PropertyDefinition>&		propertyDefinitions);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyValue						(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const API_Guid&						propertyDefinitionGuid,
																							 API_Property&							property);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyValues						(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const GS::Array<API_PropertyDefinition>&	propertyDefinitions,
																							 GS::Array<API_Property>&				properties);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyValuesByGuid				(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const GS::Array<API_Guid>&				propertyDefinitions,
																							 GS::Array<API_Property>&				properties);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetProperty							(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const API_Property&					property);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetProperties							(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const GS::Array<API_Property>&			properties);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyDefinitionsOfDefaultElem	(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 API_PropertyDefinitionFilter			filter,
																							 GS::Array<API_PropertyDefinition>&		definitions);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyValueOfDefaultElem			(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const API_Guid&						propertyDefinitionGuid,
																							 API_Property&							property);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyValuesOfDefaultElem		(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const GS::Array<API_PropertyDefinition>&	propertyDefinitions,
																							 GS::Array<API_Property>&				properties);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetPropertyValuesOfDefaultElemByGuid	(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const GS::Array<API_Guid>&				propertyDefinitions,
																							 GS::Array<API_Property>&				properties);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetPropertyOfDefaultElem				(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const API_Property&					property);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_SetPropertiesOfDefaultElem			(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const GS::Array<API_Property>&			properties);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsPropertyDefinitionValueEditable		   (ClientID							clientPtr,
																								const API_Guid&						elemGuid,
																								const API_Guid&						propertyGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsPropertyDefinitionValueEditableDefault (ClientID							clientPtr,
																								API_ElemTypeID						typeID,
																								API_ElemVariationID					variationID,
																								const API_Guid&						propertyGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsPropertyDefinitionAvailable			(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const API_Guid&						propertyGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsPropertyDefinitionAvailableDefault	(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const API_Guid&						propertyGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsPropertyDefinitionVisible			(ClientID								clientPtr,
																							 const API_Guid&						elemGuid,
																							 const API_Guid&						propertyGuid);

__APIEXPORT bool		__ACENV_CALL	ACAPI_Element_IsPropertyDefinitionVisibleDefault	(ClientID								clientPtr,
																							 API_ElemTypeID							typeID,
																							 API_ElemVariationID					variationID,
																							 const API_Guid&						propertyGuid);

__APIEXPORT GSErrCode	__ACENV_CALL    ACAPI_Element_GetCollisions (ClientID									clientPtr, 
																	 const GS::Array<API_Guid>&					apiGuidSet1,
																	 const GS::Array<API_Guid>&					apiGuidSet2,
																	 GS::Array<GS::Pair<API_CollisionElem, API_CollisionElem>>&	apiResultArray,
																	 const API_CollisionDetectionSettings&		apiColDetSettings);


__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementList_AddProperty						(ClientID								clientPtr,
																							 API_PropertyDefinition&				definition,
																							 const GS::Array<API_Guid>&				elemGuids);

__APIEXPORT GSErrCode   __ACENV_CALL	ACAPI_ElementList_ModifyPropertyValue				(ClientID								clientPtr,
																							 const API_Property&					property,
																							 const GS::Array<API_Guid>&				elemGuids);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementList_DeleteProperty					(ClientID								clientPtr,
																							 const API_Guid&						definitionGuid,
																							 const GS::Array<API_Guid>&				elemGuids);


/* -- Markup Management ------------------ */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_Create					(ClientID					clientPtr,
																			 API_MarkUpType&			markUp);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_GetList				(ClientID					clientPtr,
																			 const API_Guid&			elemGuid,
																			 GS::Array<API_MarkUpType>*	markUpList,
																			 bool*						asCorrected = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_Change					(ClientID					clientPtr,
																			 API_MarkUpType&			markUp,
																			 const bool					placeTagText = false,
																			 const API_Coord*			tagTextCoord = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_Delete					(ClientID					clientPtr,
																			 const API_Guid&			markUpGuid,
																			 const bool					keepCorrectedElems = true);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_AttachElements			(ClientID					clientPtr,
																			 const API_Guid&			markUpGuid,
																			 const GS::Array<API_Guid>&	elemList,
																			 const bool					asCorrected);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_DetachElements			(ClientID					clientPtr,
																			 const API_Guid&			markUpGuid,
																			 const GS::Array<API_Guid>&	elemList);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_GetAttachedElements	(ClientID					clientPtr,
																			 const API_Guid&			markUpGuid,
																			 GS::Array<API_Guid>*		correctedElems,
																			 GS::Array<API_Guid>*		highlightedElems);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_AddComment				(ClientID					clientPtr,
																			 const API_Guid&			markUpGuid,
																			 API_MarkUpCommentType&		comment);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_MarkUp_GetComments			(ClientID					clientPtr,
																			 const API_Guid&					markUpGuid,
																			 GS::Array<API_MarkUpCommentType>*	commentList);

/* -- Override ---------------------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_GetActualOverrideStyle				(ClientID								clientPtr,
																							 const API_Guid&						guid_Element,
																							 API_OverrideStyle&						elemOverrideStyle);

/* -- Body Editing ------------------------ */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_Create			(ClientID							clientPtr,
																	 const Modeler::MeshBody*				body,
																	 const API_OverriddenAttribute*	bodyMaterialMapTable,
																	 void**								bodyData);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_Finish			(ClientID						clientPtr,
																	 void*							bodyData,
																	 Modeler::MeshBody**				body,
																	 API_OverriddenAttribute**		bodyMaterialMapTable);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_Dispose			(ClientID				clientPtr,
																	 void**					bodyData);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_AddVertex		(ClientID				clientPtr,
																	 void*					bodyData,
																	 const API_Coord3D&		coord,
																	 UInt32&				index);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_AddEdge			(ClientID				clientPtr,
																	 void*					bodyData,
																	 const UInt32&			vertex1,
																	 const UInt32&			vertex2,
																	 Int32&					index);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_AddPolyNormal	(ClientID				clientPtr,
																	 void*					bodyData,
																	 const API_Vector3D&	normal,
																	 Int32&					index);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Body_AddPolygon		(ClientID					clientPtr,
																	 void*						bodyData,
																	 Int32*						edges,
																	 Int32						nEdges,
																	 Int32						polyNormal,
																	 API_OverriddenAttribute	material,
																	 UInt32&					index);


/* -- PolyRoof Decomposer ----------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Element_Decompose	(ClientID							clientPtr,
																 const API_Guid&					elemGuid,
																 API_ElementDecomposerInterface*	elementDecomposer);

/* -- ElementSet Manager ------------------ */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementSet_Create (ClientID				clientPtr,
																 GS::Array<API_Guid>	*guids,
																 const API_UserData		*userData,
																 API_Guid				*setGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementSet_Delete (ClientID clientPtr, API_Guid setGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementSet_GetData (ClientID				clientPtr,
																  API_Guid				setGuid,
																  GS::Array<API_Guid>	*elemGuids,
																  API_UserData			*data);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementSet_Identify (ClientID clientPtr, API_Guid elemGuid, GS::Array<API_Guid> *setGuids);


/* -- Group Manager ------------------ */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_Create (ClientID						clientPtr,
																   const GS::Array<API_Guid>&	elemGuids,
																   API_Guid*					groupGuid = nullptr,
																   const API_Guid*				parentGroupGuid = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_GetGroup (ClientID				clientPtr,
																	 const API_Guid&		elemGuid,
																	 API_Guid*				groupGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_GetRootGroup (ClientID				clientPtr,
																		 const API_Guid&		elemGuid,
																		 API_Guid*				rootGroupGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_GetGroupedElems (ClientID				clientPtr,
																			const API_Guid&			groupGuid,
																			GS::Array<API_Guid>*	elemGuids);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_GetAllGroupedElems (ClientID				clientPtr,
																			   const API_Guid&		groupGuid,
																			   GS::Array<API_Guid>*	elemGuids);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_GetUserData (ClientID			clientPtr,
																		const API_Guid&		groupGuid,
																		API_UserData*		userData);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ElementGroup_SetUserData (ClientID			clientPtr,
																		const API_Guid&		groupGuid,
																		const API_UserData*	userData);

/* -- Selection Manager ------------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Selection_Get (ClientID				clientPtr,
															 API_SelectionInfo*		selectionInfo,
															 API_Neig***			selNeigs,
															 bool					onlyEditable,
															 bool					ignorePartialSelection = true,
															 API_SelRelativePosID	relativePosToMarquee = API_InsidePartially);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Selection_SetMarquee (ClientID clientPtr, API_SelectionInfo *selectionInfo);


/* -- 3D Manager -------------------------- */

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_GetNum (ClientID clientPtr, API_3DTypeID typeID, Int32 *count);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_GetComponent (ClientID clientPtr, API_Component3D *component);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_DecomposePgon (ClientID clientPtr, Int32 ipgon, Int32 ***cpoly);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_CreateSight (ClientID clientPtr, void** newSightPtr);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_SelectSight (ClientID clientPtr, void* sight, void** oldSightPtr);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_DeleteSight (ClientID clientPtr, void* sight);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_GetCurrentWindowSight (ClientID clientPtr, void** sightPtr);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_3D_GetCutPolygonInfo (ClientID 								clientPtr,
																			Int32 									bodyIndex,
																			const API_Plane3D& 						cutPlane,
																			GS::Array<Geometry::MultiPolygon2D>* 	resPolygons = nullptr,
																			double* 								area		= nullptr);

/* -- ListData Manager -------------------- */

__APIEXPORT Int32		__ACENV_CALL	ACAPI_ListData_GetSetNum (ClientID clientPtr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ListData_GetSet (ClientID clientPtr, API_ListDataSetType *listdataSet);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ListData_GetNum (ClientID clientPtr, Int32 setIndex, API_ListDataID typeID, Int32 *count);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ListData_Get (ClientID clientPtr, API_ListData *listdata);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ListData_Search (ClientID clientPtr, API_ListData *listdata);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ListData_GetLocal (ClientID clientPtr, Int32 libIndex, const API_Elem_Head *elemHead, API_ListData *listdata);


/* -- Communication Manager ------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Command_Test	(ClientID			clientPtr,
															 const API_ModulID*	mdid,
															 GSType				cmdID,
															 Int32				cmdVersion);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Command_Call	(ClientID			clientPtr,
															 const API_ModulID*	mdid,
															 GSType				cmdID,
															 Int32				cmdVersion,
															 GSHandle			params,
															 GSPtr				resultData,
															 bool				silentMode);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Command_ExternalCall	(ClientID					clientPtr,
																	 const IO::Location*		projectFileLoc,
																	 const API_ModulID*			mdid,
																	 GSType						cmdID,
																	 Int32						cmdVersion,
																	 GSHandle					params,
																	 bool						silentMode,
																	 APIExternalCallBackProc*	externalCallbackProc);

__APIEXPORT GSErrCode __ACENV_CALL		ACAPI_Command_CallFromEventLoop (ClientID					clientPtr,
																		 const API_ModulID*			mdid,
																		 GSType						cmdID,
																		 Int32						cmdVersion,
																		 GSHandle					paramsHandle,
																		 bool						silentMode,
																		 APICommandCallBackProc*	callbackProc);

/* -- ModulData Manager ---------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ModulData_Store (ClientID clientPtr, const API_ModulData* info, const GS::UniString& modulName = "");

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ModulData_GetInfo (ClientID clientPtr, API_ModulData* info, const GS::UniString& modulName = "");

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ModulData_Get (ClientID clientPtr, API_ModulData* info, const GS::UniString& modulName = "");

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ModulData_GetList (ClientID clientPtr, GS::Array<GS::UniString>* modulNameList);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ModulData_Delete (ClientID clientPtr, const GS::UniString& modulName = "");

/* -- AddOnObject Manager ---------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_CreateObject (ClientID clientPtr, const GS::UniString& objectName, const GSHandle& content, API_Guid* objectGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_CreateUniqueObject (ClientID clientPtr, const GS::UniString& objectName, API_Guid* objectGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_CreateUniqueObjectMore (ClientID clientPtr, const GS::Array<GS::UniString>& objectNames, GS::Array<API_Guid>& objectGuids);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_GetObjectList (ClientID clientPtr, GS::Array<API_Guid>* objects);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_GetObjectContent (ClientID clientPtr, const API_Guid& objectGuid, GS::UniString* objectName, GSHandle* objectContent);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_ModifyObject (ClientID clientPtr, const API_Guid& objectGuid, const GS::UniString* newObjectName, const GSHandle* newObjectContent);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_DeleteObject (ClientID clientPtr, const API_Guid& objectGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_GetObjectGuidFromName (ClientID clientPtr, const GS::UniString& name, API_Guid* objectGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_GetUniqueObjectGuidFromName (ClientID clientPtr, const GS::UniString& name, API_Guid* objectGuid);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_ReserveObjects (ClientID clientPtr, const GS::Array<API_Guid>& objectGuids, GS::HashTable<API_Guid, short>* conflicts);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_ReleaseObjects (ClientID clientPtr, const GS::Array<API_Guid>& objectGuids);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_RequestObjects (ClientID clientPtr, const GS::Array<API_Guid>& objectGuids, const GS::UniString& mailText);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_GrantObjects (ClientID clientPtr, const GS::Array<API_Guid>& objectGuids, short toUserId, const GS::UniString* grantMailText);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_GetTeamworkOwnerId (ClientID clientPtr, const API_Guid& objectGuid, short* ownerId);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_ExistsObject (ClientID clientPtr, const API_Guid& objectGuid, bool* objectExists);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_AddOnObject_SetUIProperties (ClientID clientPtr, const API_Guid* objectGuid, const GS::UniString* name, const GS::UniString& localisedName, short dialogMenuStringId);

/* -- Notification Manager ---------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchProjectEvent		(ClientID						clientPtr,
																			 GSFlags						eventTypes,
																			 APIProjectEventHandlerProc		*handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchViewEvent			(ClientID						clientPtr,
																			 GSFlags						eventTypes,
																			 API_NavigatorMapID				mapId,
																			 APIViewEventHandlerProc		*handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchToolChange		(ClientID clientPtr, APIToolChangeHandlerProc *handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchSelectionChange	(ClientID clientPtr, APISelectionChangeHandlerProc *handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchChangeDefaults	(ClientID						clientPtr,
																			 const API_ToolBoxItem			*elemType,
																			 APIDefaultsChangeHandlerProc	*handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchNewElement		(ClientID						clientPtr,
																			 const API_ToolBoxItem			*elemType,
																			 APIElementEventHandlerProc		*handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_InstallElementObserver	(ClientID clientPtr, APIElementEventHandlerProc *handlerProc);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_GetTranParams			(ClientID clientPtr, API_ActTranPars *actTranPars);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_GetParentElement		(ClientID				clientPtr,
																			 API_Element*			element,
																			 API_ElementMemo*		memo,
																			 UInt64					mask,
																			 API_ElementUserData*	userData);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchElementReservationChange	(ClientID							clientPtr,
																					 APIReservationChangeHandlerProc*	handlerProc,
																					 const GS::HashSet<API_Guid>*		filterElementsInterestedOnly = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_CatchLockableReservationChange	(ClientID							clientPtr,
																					 APILockChangeHandlerProc*			handlerProc,
																					 const GS::HashSet<API_Guid>*		filterLockablesInterestedOnly = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_ClassificationVisibilityChanged (ClientID clientPtr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Notify_PropertyVisibilityChanged (ClientID clientPtr);


/* -- Miscellaneous ----------------------- */

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_ActivatePropertyObjectHandler (ClientID clientPtr, short strResID, bool active);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_GetDefaults (ClientID										clientPtr,
																	API_Element										*element,
																	API_ElementMemo									*memo,
																	API_Element										*elementMarker,
																	API_ElementMemo									*memoMarker,
																	GS::Array<API_Property>							*properties,
																	GS::Array<GS::Pair<API_Guid, API_Guid>>			*classifications,
																	GS::Array<API_ElemCategoryValue>				*elemCategoryValues,
																	GS::UniString									*name);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_Create (ClientID									clientPtr,
															   API_Element								*element,
															   API_ElementMemo							*memo,
															   API_Element								*elementMarker,
															   API_ElementMemo							*memoMarker,
															   const GS::Array<API_Property>			*properties,
															   const GS::Array<API_Guid>				*classifications,
															   const GS::Array<API_ElemCategoryValue>	*elemCategoryValues,
															   const API_FavoriteFolderHierarchy		*folder,
															   const GS::UniString						*name);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_Delete (ClientID clientPtr, const GS::UniString* name);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_GetNum (ClientID									clientPtr,
															   API_ElemTypeID							typeID,
															   API_ElemVariationID						variationID,
															   short									*count,
															   GS::Array<short>							*indexes,
															   GS::Array<API_FavoriteFolderHierarchy>	*folders,
															   GS::Array<GS::UniString>					*names);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_Import (ClientID										clientPtr,
															   const IO::Location&							location,
															   const API_FavoriteFolderHierarchy&			targetFolder,
															   bool											importFolders,
															   API_FavoriteNameConflictResolutionPolicy		conflictPolicy,
															   GS::UniString								*firstConflictName = nullptr);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_Read (ClientID										clientPtr,
															 const IO::Location								&location,
															 GS::Array<API_Element>							*elements,
															 GS::Array<API_ElementMemo>						*memos,
															 GS::Array<API_Element>							*elementMarkers,
															 GS::Array<API_ElementMemo>						*memoMarkers,
															 GS::Array<GS::Array<API_Property>>				*properties,
															 GS::Array<GS::Array<API_Guid>>					*classifications,
															 GS::Array<GS::Array<API_ElemCategoryValue>>	*elemCategoryValues,
															 GS::Array<API_FavoriteFolderHierarchy>			*folders,
															 GS::Array<GS::UniString>						*names);

__APIEXPORT GSErrCode	__ACENV_CALL	ACAPI_Favorite_Export (ClientID							clientPtr,
															   const IO::Location&				location,
															   const GS::Array<GS::UniString>	*names = nullptr);


/* -- Teamwork Control -------------------- */

__APIEXPORT bool				__ACENV_CALL	ACAPI_TeamworkControl_HasConnection (ClientID clientPtr);

__APIEXPORT bool				__ACENV_CALL	ACAPI_TeamworkControl_IsOnline (ClientID clientPtr);

__APIEXPORT bool				__ACENV_CALL	ACAPI_TeamworkControl_IsServerLibPart (ClientID clientPtr, const IO::Location& location);

__APIEXPORT bool				__ACENV_CALL	ACAPI_TeamworkControl_HasCreateRight (ClientID clientPtr, const API_Guid& objectId);

__APIEXPORT bool				__ACENV_CALL	ACAPI_TeamworkControl_HasDeleteModifyRight (ClientID clientPtr, const API_Guid& objectId);

__APIEXPORT API_LockableStatus	__ACENV_CALL	ACAPI_TeamworkControl_GetLockableStatus (ClientID clientPtr, const API_Guid& objectId, GS::PagedArray<GS::UniString>* conflicts = nullptr);

__APIEXPORT API_Guid			__ACENV_CALL	ACAPI_TeamworkControl_FindLockableObjectSet (ClientID clientPtr, const GS::UniString& objectSetName);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_ReserveLockable (ClientID clientPtr, const API_Guid& objectId, GS::PagedArray<GS::UniString>* conflicts = nullptr, bool enableDialogs = true);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_ReleaseLockable (ClientID clientPtr, const API_Guid& objectId, bool enableDialogs = true);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_ReserveElements (ClientID clientPtr, const GS::PagedArray<API_Guid>& objectIdArray, GS::HashTable<API_Guid, short>* conflicts = nullptr);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_ReleaseElements (ClientID clientPtr, const GS::PagedArray<API_Guid>& objectIdArray);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_ReserveHotlinkCacheManagement (ClientID clientPtr, short* conflict);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_ReleaseHotlinkCacheManagement (ClientID clientPtr);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_TeamworkControl_GetHotlinkCacheManagementOwner (ClientID clientPtr, short* owner);


/* -- Properties -------------------- */


__APIEXPORT GSErrCode			__ACENV_CALL    ACAPI_Property_GetPropertyGroups	    (ClientID clientPtr, GS::Array<API_PropertyGroup>& groups);

__APIEXPORT GSErrCode			__ACENV_CALL 	ACAPI_Property_GetPropertyDefinitions   (ClientID clientPtr, const API_Guid& groupGuid, GS::Array<API_PropertyDefinition>&	definitions);

__APIEXPORT GSErrCode			__ACENV_CALL 	ACAPI_Property_GetPropertyGroup		    (ClientID clientPtr, API_PropertyGroup& group);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_GetPropertyDefinition    (ClientID clientPtr, API_PropertyDefinition& definition);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_CreatePropertyGroup	    (ClientID clientPtr, API_PropertyGroup& group);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_CreatePropertyDefinition	(ClientID clientPtr, API_PropertyDefinition& definition);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_ChangePropertyGroup		(ClientID clientPtr, const API_PropertyGroup& group);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_ChangePropertyDefinition	(ClientID clientPtr, const API_PropertyDefinition& definition);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_DeletePropertyGroup		(ClientID clientPtr, const API_Guid& groupGuid);

__APIEXPORT GSErrCode			__ACENV_CALL	ACAPI_Property_DeletePropertyDefinition	(ClientID clientPtr, const API_Guid& propertyGuid);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Property_Import					(ClientID												clientPtr,
																						 const GS::UniString&									propertyXML,
																						 API_PropertyDefinitionNameConflictResolutionPolicy		conflictPolicy);

/* -- Classifications -------------------- */

__APIEXPORT GSErrCode			__ACENV_CALL    ACAPI_Classification_GetClassificationSystems			(ClientID clientPtr, GS::Array<API_ClassificationSystem>& systems);

__APIEXPORT GSErrCode			__ACENV_CALL    ACAPI_Classification_GetClassificationItem				(ClientID clientPtr, API_ClassificationItem& item);

__APIEXPORT GSErrCode			__ACENV_CALL    ACAPI_Classification_GetClassificationItemParent		(ClientID clientPtr, const API_Guid& itemGuid, API_ClassificationItem& parent);

__APIEXPORT GSErrCode			__ACENV_CALL    ACAPI_Classification_GetClassificationItemChildren		(ClientID clientPtr, const API_Guid& itemGuid, GS::Array<API_ClassificationItem>& children);

__APIEXPORT GSErrCode			__ACENV_CALL    ACAPI_Classification_GetClassificationItemSystem		(ClientID clientPtr, const API_Guid& itemGuid, API_ClassificationSystem& system);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_GetClassificationSystem			(ClientID clientPtr, API_ClassificationSystem& system);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_GetClassificationSystemRootItems	(ClientID clientPtr, const API_Guid& systemGuid, GS::Array<API_ClassificationItem>& items);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_CreateClassificationItem			(ClientID clientPtr,
																										 API_ClassificationItem& item,
																										 const API_Guid& systemGuid,
																										 const API_Guid& parentItemGuid,
																										 const API_Guid& nextItemGuid);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_CreateClassificationSystem			(ClientID clientPtr, API_ClassificationSystem& system);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_ChangeClassificationItem			(ClientID clientPtr, const API_ClassificationItem& item);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_ChangeClassificationSystem			(ClientID clientPtr, const API_ClassificationSystem& system);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_DeleteClassificationItem			(ClientID clientPtr, const API_Guid& itemGuid);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_DeleteClassificationSystem			(ClientID clientPtr, const API_Guid& systemGuid);

__APIEXPORT GSErrCode 			__ACENV_CALL	ACAPI_Classification_Import								(ClientID												clientPtr,
																										 const GS::UniString&									classificationXML,
																										 API_ClassificationSystemNameConflictResolutionPolicy	systemConflictPolicy,
																										 API_ClassificationItemNameConflictResolutionPolicy		itemConflictPolicy);

/* --> ] */
#endif


// ---------------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)
	#pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif
