interface Person {
  firstName: string
  lastName: string
}

/**
 * Student
 */
class Student {
  fullName: string

  constructor(public firstName, public middleName, public lastName) {
    this.fullName = firstName + middleName + lastName
  }
}

function greeter(person: Person) {
  return "Hello " + person.firstName + " " + person.lastName
}

var user = new Student("Jane", "M.", "User")

document.body.innerHTML = greeter(user);