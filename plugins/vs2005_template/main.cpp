//
// This is a template for easy creation of IDA Plugins using
// MS Visual Studio 2005 or later (ie VS2008 or VS2010)
// 
// This helps by setting all required settings, paths and preprocessor values
// required to create both 32bit and 64bit plugins from the same sourcecode.
// This will save work and time even for those with experience writing plugins,
// but it is of most use for those who are new to it and don't know where to start.
// 
// All that you as a plugin writer needs to do now is fill in your own values
// for the strings and functions in the "plugin_t PLUGIN" structure below.
//
// Note: When building these samples, your plugin file will be created in the
// "idasdk/bin/plugins" directory. To install the plugin copy the created files
// to the "IDA/plugins" directory.
//
// Zak Stanborough - October 2009
// 


// A bunch of required headers from the IDA SDK
#include <ida.hpp>
#include <idp.hpp>
#include <name.hpp>
#include <bytes.hpp>
#include <loader.hpp>
#include <kernwin.hpp>



// Determines whether this plugin will work with the current database.
// 
// IDA will call this function only once. If this function returns PLUGIN_SKIP,
// IDA will never load it again. If it returns PLUGIN_OK, IDA will unload the plugin
// but remember that the plugin agreed to work with the database. The plugin will
// be loaded again if the user invokes it by pressing the hotkey or selecting it
// from the menu. After the second load, the plugin will stay in memory.
// 
// returns:	PLUGIN_OK if plugin is supported, PLUGIN_SKIP if plugin isn't supported
int idaapi PluginStartup(void)
{
	// Insert tests here to determine if this plugin can be used
	// with the database being loaded. A common test is to check the
	// processor type for plugins that only support particular processors.
	
	// This tests if the processor type is PPC
	// If it is PPC then return OK to show that the plugin is supported
	if ( ph.id == PLFM_PPC )
		return PLUGIN_OK;
	
	// If the processor isn't PPC then this plugin should not be used
	// with the database being loaded, so return SKIP.
	return PLUGIN_SKIP;
}


// IDA will call this function when the user asks to exit. This function is *not*
// called in the case of emergency exits.
void idaapi PluginShutdown(void)
{
	// Any cleanup code that needs to be done on exit goes here
}


// This is the main plugin function. This code gets executed everytime
// your plugin is executed.
// 
// args:	param: Input argument specified in the "plugins.cfg" file.
void idaapi PluginMain(int param)
{
	info("Hello world!");
}



// 
// Strings required for IDA Pro's PLUGIN descriptor block
// 

const char G_PLUGIN_COMMENT[]	=	"VS2005 IDA Plugin Template";
const char G_PLUGIN_HELP[]		=	"This is a template to help you easily write both 32bit and 64bit"
									"plugins for IDA in MS Visual Studio 2005 or later.\n";
const char G_PLUGIN_NAME[]		=	"VS2005 Template";
const char G_PLUGIN_HOTKEY[]	=	"Ctrl-F11";



// 
// This 'PLUGIN' data block is how IDA Pro interfaces with this plugin.
// 
plugin_t PLUGIN =
{
	// values
	IDP_INTERFACE_VERSION,
	0,						// plugin flags
	
	// functions
	PluginStartup,			// initialize and test if pluginis supported
	PluginShutdown,			// terminate. this pointer may be NULL.
	PluginMain,				// invoke plugin
	
	// strings
	(char*)G_PLUGIN_COMMENT,// long comment about the plugin (may appear on status line or as a hint)
	(char*)G_PLUGIN_HELP,	// multiline help about the plugin
	(char*)G_PLUGIN_NAME,	// the preferred short name of the plugin, used by menu system
	(char*)G_PLUGIN_HOTKEY	// the preferred hotkey to run the plugin
};

