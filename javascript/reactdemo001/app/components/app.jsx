import uuid from 'node-uuid';
import React from 'react';
import Notes from './notes.jsx';

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      notes: [
        {
          id: uuid.v4(),
          task: 'Learning webpack'
        }, {
          id: uuid.v4(),
          task: 'Learning React'
        }, {
          id: uuid.v4(),
          task: 'Do laundry'
        }
      ]
    };
    
    this.addNote = this.addNote.bind(this);
    this.findNote = this.findNote.bind(this);
    this.editNote = this.editNote.bind(this);
    this.deleteNote = this.deleteNote.bind(this);
  }

  render() {
    const notes = this.state.notes;
    return (
      <div>
        <button className="add-note" onClick={this.addNote}>+</button>
        <Notes items={notes} onEdit={this.editNote} onDelete={this.deleteNote} />
      </div>
    );
  }

  addNote() {
    this.setState({
      notes: this.state.notes.concat([{
        id: uuid.v4(),
        task: 'New Task'
      }])
    });
  }

  editNote(id, task) {
    let notes = this.state.notes;

    let noteIndex = this.findNote(id);

    if (noteIndex < 0) {
      return;
    }

    notes[noteIndex] = {task: task};
    this.setState(notes);
  }

  findNote(id) {
    let notes = this.state.notes;
    let noteIndex = notes.findIndex((note) => note.id === id);

    if (noteIndex < 0 ) {
      console.warn('Failed to find note', notes, id);
    }

    return noteIndex;
  }

  deleteNote(id) {
    let notes = this.state.notes;

    let noteIndex = this.findNote(id);

    if (noteIndex < 0) {
      return;
    }

    notes.splice(noteIndex, 1);
    this.setState(notes);
  }
}
