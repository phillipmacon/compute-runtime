/*
 * Copyright (C) 2019-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "gmm_helper/gmm_helper.h"
#include "gmm_helper/page_table_mngr.h"
#include "opencl/source/platform/platform.h"

#include "gmm_client_context.h"

namespace NEO {
GmmPageTableMngr::GmmPageTableMngr(GmmClientContext *gmmClientContext, unsigned int translationTableFlags, GMM_TRANSLATIONTABLE_CALLBACKS *translationTableCb) : clientContext(gmmClientContext->getHandle()) {
    pageTableManager = clientContext->CreatePageTblMgrObject(translationTableCb, translationTableFlags);
}

void GmmPageTableMngr::setCsrHandle(void *csrHandle) {
    pageTableManager->GmmSetCsrHandle(csrHandle);
}
} // namespace NEO
