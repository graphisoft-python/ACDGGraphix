#pragma once

#include "../stdafx.h"

#include "DGUserItem.hpp"
#include "DGListBox.hpp"
#include "DGNativeContexts.hpp"

using namespace NewDisplay;


// --- UserItemUpdateNativeContext -----------------------------------------------------

void load_UserItemUpdateNativeContext(py::module m) {
	py::class_<UserItemUpdateNativeContext, NativeContext>(m, "UserItemUpdateNativeContext")
		.def(py::init<DG::UserItemUpdateEvent &>())
		//.def(py::init<>())
		//.def(py::init<>())
		;
}


// --- ListBoxUpdateEventContext -----------------------------------------------------

void load_ListBoxUpdateEventContext(py::module m) {
	py::class_<ListBoxUpdateEventContext, NativeContext>(m, "ListBoxUpdateEventContext")
		.def(py::init<DG::ListBoxItemUpdateEvent &>())
		//.def(py::init<>())
		//.def(py::init<>())
		;
}
