/* Copyright 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_SYNC_BOOKMARK_MODEL_LOADED_ONLY_OBSERVER_H_
#define BRAVE_COMPONENTS_BRAVE_SYNC_BOOKMARK_MODEL_LOADED_ONLY_OBSERVER_H_

#include <set>

#include "components/bookmarks/browser/bookmark_model_observer.h"

namespace brave_sync {

using bookmarks::BookmarkModel;
using bookmarks::BookmarkNode;

// This is a wrapper for the BookmarkModelObserver if we need only
// BookmarkModelLoaded notification
class BookmarkModelLoadedOnlyObserver
    : public bookmarks::BookmarkModelObserver {
 public:
  BookmarkModelLoadedOnlyObserver() = default;
  ~BookmarkModelLoadedOnlyObserver() override = default;

 protected:
  // bookmarks::BookmarkModelObserver implementation
  void BookmarkModelLoaded(BookmarkModel* model, bool ids_reassigned) override {
  }

 private:
  void BookmarkNodeMoved(BookmarkModel* model,
                         const BookmarkNode* old_parent,
                         size_t old_index,
                         const BookmarkNode* new_parent,
                         size_t new_index) override {}

  void BookmarkNodeAdded(BookmarkModel* model,
                         const BookmarkNode* parent,
                         size_t index) override {}

  void BookmarkNodeRemoved(
      BookmarkModel* model,
      const BookmarkNode* parent,
      size_t old_index,
      const BookmarkNode* node,
      const std::set<GURL>& no_longer_bookmarked) override {}

  void BookmarkNodeChanged(BookmarkModel* model,
                           const BookmarkNode* node) override {}

  void BookmarkNodeFaviconChanged(BookmarkModel* model,
                                  const BookmarkNode* node) override {}

  void BookmarkNodeChildrenReordered(BookmarkModel* model,
                                     const BookmarkNode* node) override {}

  void BookmarkAllUserNodesRemoved(
      BookmarkModel* model,
      const std::set<GURL>& removed_urls) override {}
};

}  // namespace brave_sync

#endif  // BRAVE_COMPONENTS_BRAVE_SYNC_BOOKMARK_MODEL_LOADED_ONLY_OBSERVER_H_
