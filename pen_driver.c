#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

//probe function
//called on device insertion if no other driver has already taken control
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO "[*] John's Pen drive (%04X:%04X) is plugged\n", id->idVendor, id->idProduct);
	return 0; //indicates we will manage this device
}

//disconnect
static void pen_disconnect(struct usb_interface *interface){
	printk(KERN_INFO "[*] John's Pen drive is removed\n");
}

// usb_device_id
static struct usb_device_id pen_table[] = {
	//090c:1000
	{ USB_DEVICE(0x090c, 0x1000) }, //Vender Id, product Id, from "lsusb" command
	{} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, pen_table);

// usb_driver
static struct usb_driver pen_driver =
{
	.name = "John's Pen Driver",
	.id_table = pen_table,
	.probe = pen_probe,
	.disconnect = pen_disconnect,
};

static int __init pen_init(void){
	int ret = -1;
	printk(KERN_INFO "[*]Constructor of driver");
	printk(KERN_INFO "\tRegistering Driver with Kernel");
	ret = usb_register(&pen_driver);
	printk(KERN_INFO "\tRegistration is complete");
	return ret;
}

static void __exit pen_exit(void){
	//deregister
	printk(KERN_INFO "[*] Destructor of driver");
	usb_deregister(&pen_driver);
	printk(KERN_INFO "\tunregistration complete!");
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("John Wang");
MODULE_DESCRIPTION("USB Pen Driver Registration");
