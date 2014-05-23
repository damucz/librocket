/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "precompiled.h"
#include "XMLNodeHandlerTemplate.h"
#include "Template.h"
#include "TemplateCache.h"
#include "XMLParseTools.h"
#include <Rocket/Core.h>

namespace Rocket {
namespace Core {

XMLNodeHandlerTemplate::XMLNodeHandlerTemplate()
{
}

XMLNodeHandlerTemplate::~XMLNodeHandlerTemplate()
{
}

Element* XMLNodeHandlerTemplate::ElementStart(XMLParser* parser, const String& name, const XMLAttributes& attributes)
{
	name;
	ROCKET_ASSERT(name == "template");
	(name);

	String template_name = attributes.Get<String>("src", "");

	// Tell the parser to use the element handler for all child nodes
	parser->PushDefaultHandler();

	return XMLParseTools::ParseTemplate(parser->GetParseFrame()->element, template_name);
}

bool XMLNodeHandlerTemplate::ElementEnd(XMLParser* ROCKET_UNUSED(parser), const String& ROCKET_UNUSED(name))
{
	return true;
}

bool XMLNodeHandlerTemplate::ElementData(XMLParser* parser, const String& data)
{	
	return Factory::Instance()->InstanceElementText(parser->GetParseFrame()->element, data);
}

void XMLNodeHandlerTemplate::Release()
{
	delete this;
}

}
}
