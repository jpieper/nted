/****************************************************************************************/
/*											*/
/* This program is free software; you can redistribute it and/or modify it under the	*/
/* terms of the GNU General Public License as published by the Free Software		*/
/* Foundation; either version 2 of the License, or (at your option) any later version.	*/
/*											*/
/* This program is distributed in the hope that it will be useful, but WITHOUT ANY	*/
/* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A	*/
/* PARTICULAR PURPOSE. See the GNU General Public License for more details.		*/
/*											*/
/* You should have received a copy of the GNU General Public License along with this	*/
/* program; (See "COPYING"). If not, If not, see <http://www.gnu.org/licenses/>.        */
/*											*/
/*--------------------------------------------------------------------------------------*/
/*											*/
/*  Copyright   Joerg Anders, TU Chemnitz, Fakultaet fuer Informatik, GERMANY           */
/*		ja@informatik.tu-chemnitz.de						*/
/*											*/
/*											*/
/****************************************************************************************/

#ifndef CLEF_CONTEXT_DIALOG_H

#define CLEF_CONTEXT_DIALOG_H
#include "config.h"
#include <gtk/gtk.h>
#include <cairo.h>



class NedClefConfigDialog {
	public:
		NedClefConfigDialog(GtkWindow *parent, int clef_number, int octave_shift);
		void getValues(bool *state, int *clef_number, int *octave_shift, bool *adjust_notes);
	private:
		static void OnClose(GtkDialog *dialog, gint result, gpointer data);
		static gboolean OnScroll(GtkWidget *widget, GdkEventScroll *event, gpointer data);
		static gboolean draw_clefs(GtkWidget *widget,
			 GdkEventExpose *event, gpointer data);
		static void decrease_clef_number (GtkButton *button, gpointer user_data);
		static void increase_clef_number (GtkButton *button, gpointer user_data);
		static void octave_shift_change(GtkSpinButton *spinbutton, gpointer user_data);
		GtkWidget *m_clef_show_window;
		GtkWidget *m_clef_bu_up;
		GtkWidget *m_clef_bu_down;
		GtkWidget *m_octave_shift_spin_box;
		GtkWidget *m_adjust_check_box;
		int m_octave_shift;
		bool m_state;
		bool m_do_adjust;
		int m_current_clef, m_newclef;
};

#endif /* CLEF_CONTEXT_DIALOG_H */
