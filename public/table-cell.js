import {
  LitElement,
  css,
  html,
} from "https://unpkg.com/lit-element@2.2.1/lit-element.js?module";

export class TableCell extends LitElement {
  static get styles() {
    return css`
      div {
        font-weight: bold;
        border-style: solid;
        color: pizza;
        padding: 1em;
      }
    `;
  }
  static properties = {};

  constructor() {
    super();
  }

  render() {
    return html`
        <div><slot></slot></div>
    `;
  }
}

customElements.define("table-cell", TableCell);
