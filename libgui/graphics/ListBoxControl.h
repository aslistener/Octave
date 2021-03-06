/*

Copyright (C) 2011-2016 Michael Goffioul

This file is part of Octave.

Octave is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

Octave is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, see
<http://www.gnu.org/licenses/>.

*/

#if ! defined (octave_ListBoxControl_h)
#define octave_ListBoxControl_h 1

#include "BaseControl.h"

class QListWidget;
class QListWidgetItem;
class QModelIndex;

namespace QtHandles
{

  class ListBoxControl : public BaseControl
  {
    Q_OBJECT

  public:
    ListBoxControl (const graphics_object& go, QListWidget* list);
    ~ListBoxControl (void);

    static ListBoxControl* create (const graphics_object& go);

  protected:
    void update (int pId);
    bool eventFilter (QObject* watched, QEvent* e);
    void sendSelectionChange();

  private slots:
    void itemSelectionChanged (void);
    void itemActivated (const QModelIndex &);
    void itemPressed (QListWidgetItem*);

  private:
    bool m_blockCallback;
    bool m_selectionChanged;
  };

}

#endif

