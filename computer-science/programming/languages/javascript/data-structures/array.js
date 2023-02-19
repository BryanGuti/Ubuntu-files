class List {
  constructor() {
    this.length = 0;
  }

  push(...params) {
    for (const item of params) {
      this[this.length] = item;
      this.length ++;
    }
    return this.length;
  }

  pop() {
    const element = this[this.length - 1];

    delete this[this.length - 1];
    this.length--;

    return element;
  }

  shift() {
    if (!(this.length > 0)) return;

    const element = this[0];
    delete this[0];
    this.length--;

    for(let i = 0; i < this.length;) {
      this[i] = this[++i];
    }

    delete this[this.length];

    return element;
  }

  unshift(...params) {
    const mov = params.length;

    for (let i = this.length - 1; i >= 0; i--) {
      this[i + mov] = this[i];
    }

    for (let i = 0; i < mov; i++) {
      this[i] = params[i];
      this.length++;
    }

    return this.length;
  }
}