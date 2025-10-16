// Find
	case WM_ACTIVATEAPP:
	{
		// ...
		if (m_isActivateWnd)
		{
			// ...
		}
		else
		{
			// ...

// Add here
			if (IsUserMovingMainWindow())
				SetUserMovingMainWindow(false);
		}
	}



// Find and change
	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE && IsUserMovingMainWindow())
			SetUserMovingMainWindow(false);

		// ....
	}
	break;



// Find and change
	case WM_LBUTTONDOWN:
		// ...

		// Add
		if (IsUserMovingMainWindow())
			SetUserMovingMainWindow(false);

		return 0;





// Find
case WM_EXITSIZEMOVE:
{
...
}

// Add
	case WM_NCLBUTTONDOWN:
	{
		switch (wParam)
		{
		case HTMAXBUTTON:
		case HTSYSMENU:
			return 0;
		case HTMINBUTTON:
			ShowWindow(hWnd, SW_MINIMIZE);
			return 0;
		case HTCLOSE:
			RunPressExitKey();
			return 0;
		case HTCAPTION:
			if (!IsUserMovingMainWindow())
				SetUserMovingMainWindow(true);

			return 0;
		}

		break;
	}
	
	case WM_NCLBUTTONUP:
	{
		if (IsUserMovingMainWindow())
			SetUserMovingMainWindow(false);
		
		break;
	}

	case WM_NCRBUTTONDOWN:
	case WM_NCRBUTTONUP:
	case WM_CONTEXTMENU:
		return 0;
	case WM_SYSCOMMAND:
		if (wParam == SC_KEYMENU)
			return 0;
		break;
