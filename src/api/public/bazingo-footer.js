import {
    LitElement,
    css,
    html,
  } from "https://unpkg.com/lit-element@2.2.1/lit-element.js?module";
  
  export class BazingoFooter extends LitElement {
    static get styles() {
      return css`
        div {
          font-weight: bold;
          border-style: solid;
          color: black;
        }
      `;
    }
    static properties = {};
  
    constructor() {
      super();
    }
  
    render() {
      return html`
          <footer>Powered by Leta Technology 2022</footer>
      `;
    }
  }
  
  customElements.define("bazingo-footer", BazingoFooter);
  