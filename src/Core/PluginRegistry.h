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

#ifndef ROCKETCOREPLUGINREGISTRY_H
#define ROCKETCOREPLUGINREGISTRY_H

namespace Rocket {
namespace Core {

class Context;
class Element;
class ElementDocument;
class Plugin;

/**
	@author Peter Curry
 */

class PluginRegistry
{
public:
  static PluginRegistry* Instance()
  {
    return s;
  }

  static PluginRegistry* CreateInstance()
  {
    if (!s)
      s = new PluginRegistry;
    return s;
  }

  static void DestroyInstance()
  {
    if (s)
      delete s;
    s = NULL;
  }

	void RegisterPlugin(Plugin* plugin);

	/// Calls OnInitialise() on all plugins.
	void NotifyInitialise();
	/// Calls OnShutdown() on all plugins.
	void NotifyShutdown();

	/// Calls OnContextCreate() on all plugins.
	void NotifyContextCreate(Context* context);
	/// Calls OnContextDestroy() on all plugins.
	void NotifyContextDestroy(Context* context);

	/// Calls OnDocumentOpen() on all plugins.
	void NotifyDocumentOpen(Context* context, const String& document_path);
	/// Calls OnDocumentLoad() on all plugins.
	void NotifyDocumentLoad(ElementDocument* document);
	/// Calls OnDocumentUnload() on all plugins.
	void NotifyDocumentUnload(ElementDocument* document);

	/// Calls OnElementCreate() on all plugins.
	void NotifyElementCreate(Element* element);
	/// Calls OnElementDestroy() on all plugins.
	void NotifyElementDestroy(Element* element);

  typedef std::vector< Plugin* > PluginList;
  PluginList basic_plugins;
  PluginList document_plugins;
  PluginList element_plugins;
private:
	PluginRegistry();
  PluginRegistry(const PluginRegistry &);

  static PluginRegistry *s;
};

}
}

#endif
