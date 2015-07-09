/**
* TUL patterns
*
* @author Kevin Robert Stravers
* @version 1.0.0
*/
Rainbow.extend('tul', [
	{
		'name': 'constant',
		'pattern': /\b(false|null|true|\d+|\d+(K|M|G|T|P|E|Z|Y|X|W))\b/g // Kilo, Mega, Giga, Tera, Peta, Exa, Zetta, Yotta, Xona, Weka
	},
	{
		'name': 'keyword',
		'pattern': /\b(\d+u|\d+s|adr|break|case|cast|const|continue|default|defer|do|dref|else|false|for|goto|if|new|private|ptr|public|ref|restricted|return|switch|this|while)\b/g
	},
  {
    'name': 'variable',
    'pattern': /\b(([a-zA-Z]_?)+)\b/g
  },
  /*
    {
        'matches': {
            1: 'keyword',
            2: {
                'name': 'support.class',
                'pattern': /\w+/g
            }
        },
        'pattern': /(typeof)\s([^\$].*?)(\)|;)/g
    },
    {
        'matches': {
            1: 'keyword.namespace',
            2: {
                'name': 'support.namespace',
                'pattern': /\w+/g
            }
        },
        'pattern': /\b(namespace)\s(.*?);/g
    },
    {
        'matches': {
            1: 'storage.modifier',
            2: 'storage.class',
            3: 'entity.name.class',
            4: 'storage.modifier.extends',
            5: 'entity.other.inherited-class'
        },
        'pattern': /\b(abstract|sealed)?\s?(class)\s(\w+)(\sextends\s)?([\w\\]*)?\s?\{?(\n|\})/g
    },
    {
        'name': 'keyword.static',
        'pattern': /\b(static)\b/g
    },
    {
        'matches': {
            1: 'keyword.new',
			2: {
                'name': 'support.class',
                'pattern': /\w+/g
            }

        },
        'pattern': /\b(new)\s([^\$].*?)(?=\)|\(|;|&)/g
    },
    */
	{
		'name': 'string',
		'pattern': /(")(.*?)\1|(')(.)\1/g
	},
	{
    'name': 'comment',
    'pattern': /\/\*[\s\S]*?\*\/|(\/\/)[\s\S]*?$/gm
  },
	{
		'name': 'operator',
		'pattern': /(\+\+|\+=|\+|--|-=|-|&lt;&lt;=|&lt;&lt;|&lt;=|=&gt;|&gt;|&lt;|&gt;&gt;=|&gt;&gt;|&gt;=|!=|!|~|\^|\|\||&amp;&amp;|&amp;=|&amp;|\?\?|::|:|\*=|\*|\/=|%=|\|=|==|=)/g
	},
  {
    'name': 'preprocessor',
    'pattern': /#[\s\S]*?\)/gm
  },
  {
    'name': 'braces',
    'pattern': /\{|\}/gm
  }
], true);
