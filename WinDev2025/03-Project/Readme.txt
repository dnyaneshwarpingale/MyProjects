Application run kelya kelya black window aali pahije and centrally green text "click on file menu and select open to open an image file " left top matched with desktop left top . and window should occupy 1/4th of your desktop .

Menu Bar.==>

notes page-> 143 - 5th chapter Menu -bar
    file
	open file==> page -208
	exit
    edit
	edit image ==> on click edit image dialog box opened. add about button with ok and Exit.
    help
	about=>about dialog box 

window should not be resize .. clamp the value.

about dialog box centrally ala pahije. 

specification 
About.
icon(page132) and dialog box background color is black. => notes==126

write text 
iconchya samor Image Editor 
   by
first name middle name last name
	Astromedicomp

emailed:-

		ok



lec 03-Dec
Main Dialog Box
==>  
	background color ,candy, pestarn ,baby colors
	Caption -"Image Editor and Color Picker"
	
	Top half =Image editor
       
	Push Button Register user=> on click register user dialog box
					caption user registration
					3-edit text
					EDITTEXT username
					ctext 
					pushButton Register.
					Spot validation.
					enablewindow.
					Edittextboxnotification

				killFocus,
Radiobutton
	Group Box
		Image Editor
		Group Box
			Dsaturation
			2- radioButtons
			reset Image
		Group Box
			Sephiya
			2- radioButtons
			reset Image
		Group Box
			Color Inversion
			2- radioButtons
			reset Image


Radio button
	Group Box
		Color Picker.
     when color picker enabled then when we move our cursor in image cursor will change.
   3-text boxes for rgb values non editable.always disable.
   colorboxes for picked color.



	

	chekedboxes => export picked colors log files
			and normalized colors log.


04 dec

log file format

save logfile with registered user.

on register button click purn time. capture karacha aahe.
names like firstnameSurname-userLog-dd-mm-yyyy-hour.txt
			register username 
			user registration time.dd/mm/yyyy
			USER LOG:
			
			USER EXITED TIME AND DATE.
           firstnamesurname-pickedcolorlog-userregistrationtime.txt
                        register username 
			user registration time.dd/mm/yyyy
	   firstnamesurname-pickedcolornormalizedColorlog-userregistrationtime.txt
				register username 
			user registration time.dd/mm/yyyy



wM_COMMAND IN DIALOGBOX.
	Pv_register:
	STRUCTURE SYSTEMTIME
          getsystem time() SEARCH ON MSDN.

COM HOMEWORK.

	COM Aggregation implement karaych.
	 name should not like inner dll and outer dll
	
	
class IDsaturation : pblic IUnknown
{
	HRESULT __stdcall dsaturation(COLORREF originalpixelColor,COLORREF * dsaturatedColor) =0;
}
class Isepia : public IUnknown
{
      HRESULT __stdcall sepia(COLORREF originalpixelColor,COLORREF * sepiaColor) =0;
}
like that.

        
	




	



