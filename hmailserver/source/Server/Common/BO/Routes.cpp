// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "Routes.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   Routes::Routes()
   {
      
   }

   Routes::~Routes()
   {

   }

   void 
   Routes::Refresh()
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Reloads all routes from the database.
   //---------------------------------------------------------------------------()
   {
      String sSQL = "select * from hm_routes order by routedomainname asc";
      DBLoad_(sSQL);
   }

   shared_ptr<Route> 
   Routes::GetItemByNameWithWildcardMatch(const String &domainName)
   {
      vector<shared_ptr<Route> >::iterator iter = vecObjects.begin();
      vector<shared_ptr<Route> >::iterator iterEnd = vecObjects.end();

      for (; iter != iterEnd; iter++)
      {
         shared_ptr<Route> pRoute = (*iter);

         if (StringParser::WildcardMatchNoCase(pRoute->DomainName(), domainName))
         {
            return pRoute;
         }
      }

      shared_ptr<Route> empty;
      return empty;
   }

}
