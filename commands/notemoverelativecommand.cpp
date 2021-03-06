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

#include "notemoverelativecommand.h"
#include "note.h"
#include "chordorrest.h"
#include "mainwindow.h"

NedMoveNoteRelativeCommand::NedMoveNoteRelativeCommand(NedNote *note, int dist) :
m_note(note) {
	m_from = note->getLine();
	m_to = m_from + dist;
}

void NedMoveNoteRelativeCommand::execute(bool adjust /* = false */) {
#ifdef EXECUTE_DEBUG
	printf("\tNedMoveNoteRelativeCommand::execute\n");
#endif
	m_note->moveUpDown(m_to);
	m_note->getChord()->reConfigure();
	m_note->getChord()->xPositNotes();
	m_note->getChord()->computeBbox();
	if (adjust) {
		m_note->getMainWindow()->setVisible(m_note);
	}
}

void NedMoveNoteRelativeCommand::unexecute(bool adjust /* = false */) {
#ifdef UNEXECUTE_DEBUG
	printf("\tNedMoveNoteRelativeCommand::unexecute\n");
#endif
	m_note->moveUpDown(m_from);
	m_note->getChord()->reConfigure();
	m_note->getChord()->xPositNotes();
	m_note->getChord()->computeBbox();
	if (adjust) {
		m_note->getMainWindow()->setVisible(m_note);
	}
}

	

