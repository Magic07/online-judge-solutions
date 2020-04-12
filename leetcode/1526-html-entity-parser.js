/**
 * @param {string} text
 * @return {string}
 */
var entityParser = function(text) {
  text=text.replace(/&quot;/g, '"');
  text=text.replace(/&apos;/g, "'");
  text=text.replace(/&amp;/g, '&');
  text=text.replace(/&gt;/g, '>');
  text=text.replace(/&lt;/g, '<');
  text=text.replace(/&frasl;/g, '/');
  return text;
};