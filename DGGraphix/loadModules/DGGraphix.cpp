// DGGraphix.cpp : 定义 DLL 应用程序的导出函数。
#include "../stdafx.h"

#include "../implementations/DGNativeContextFunc.hpp"


PYBIND11_MODULE(DGGraphix, m) {

	m.def("version", []() {	return "version 0.0.1"; });

	// --- Add bindings here ------------------------------------------------------------------


	// --- DGNativeContext
	load_UserItemUpdateNativeContext(m);
	load_ListBoxUpdateEventContext(m);

	// --- Add bindings end -------------------------------------------------------------------
}